#include "StarObj.h"
#include <cmath>
#include "Core/Loger.h"

#include "Core/Draw.h"

StarObj::StarObj(Vector2 p_position, std::string p_textureID, float p_angle, float p_diametre)
    : Entity(p_position, p_textureID, p_angle), m_diametre(p_diametre)
{
    m_vitesse = { 0.f, 0.f };

    m_rayon = m_diametre / 2.f;
    m_rect = {
        m_position + Vector2 {  m_rayon,  m_rayon },                      //p1
        m_position + Vector2 { -m_rayon,  m_rayon },                      //p2
        m_position + Vector2 { -m_rayon, -m_rayon },                      //p3
        m_position + Vector2 {  m_rayon, -m_rayon }                       //P4
    };

    m_bigRayon = Distance(m_rect.p1, m_rect.p3) / 2.f;

    m_rectCrit = {
        DegToRad(45.f),
        DegToRad(135.f),
        DegToRad(225.f),
        DegToRad(315.f)
    };

    m_losa = {
        m_position + RotationTransform(m_rect.p1 - m_position, Pi / 4.f),
        m_position + RotationTransform(m_rect.p2 - m_position, Pi / 4.f),
        m_position + RotationTransform(m_rect.p3 - m_position, Pi / 4.f),
        m_position + RotationTransform(m_rect.p4 - m_position, Pi / 4.f)
    };

    m_losaCrit = {
        m_rectCrit.p1 + Pi / 4.f,
        m_rectCrit.p2 + Pi / 4.f,
        m_rectCrit.p3 + Pi / 4.f,
        NormalizeRad(m_rectCrit.p4 + Pi / 4.f)
    };

    float beta = 0.414f * m_diametre;
    float alpha = (m_diametre - beta) / 2.f;

    m_oct = {
        { m_rect.p1.x, m_rect.p1.y - alpha },            // p1
        { m_rect.p1.x - alpha, m_rect.p1.y },            // p2
        { m_rect.p2.x + alpha, m_rect.p1.y },            // p3
        { m_rect.p2.x, m_rect.p2.y - alpha },            // p4
        { m_rect.p2.x, m_rect.p3.y + alpha },            // p5
        { m_rect.p3.x + alpha, m_rect.p3.y },            // p6
        { m_rect.p4.x - alpha, m_rect.p4.y },            // p7
        { m_rect.p4.x, m_rect.p4.y + alpha }             // p8
    };

    m_octCrit = {
        DegToRad(22.5f),
        DegToRad(67.5f),
        DegToRad(112.5f),
        DegToRad(157.5f),
        DegToRad(202.5f),
        DegToRad(247.5f),
        DegToRad(292.5f),
        DegToRad(337.5f)
    };
}

void StarObj::UpdateStarPositions()
{
    m_rect = {
        m_position + Vector2 {  m_rayon,  m_rayon },                      //p1
        m_position + Vector2 { -m_rayon,  m_rayon },                      //p2
        m_position + Vector2 { -m_rayon, -m_rayon },                      //p3
        m_position + Vector2 {  m_rayon, -m_rayon }                       //P4
    };

    m_losa = {
        m_position + RotationTransform(m_rect.p1 - m_position, Pi / 4.f),
        m_position + RotationTransform(m_rect.p2 - m_position, Pi / 4.f),
        m_position + RotationTransform(m_rect.p3 - m_position, Pi / 4.f),
        m_position + RotationTransform(m_rect.p4 - m_position, Pi / 4.f)
    };

    float beta = 0.414f * m_diametre;
    float alpha = (m_diametre - beta) / 2.f;

    m_oct = {
        { m_rect.p1.x, m_rect.p1.y - alpha },            // p1
        { m_rect.p1.x - alpha, m_rect.p1.y },            // p2
        { m_rect.p2.x + alpha, m_rect.p1.y },            // p3
        { m_rect.p2.x, m_rect.p2.y - alpha },            // p4
        { m_rect.p2.x, m_rect.p3.y + alpha },            // p5
        { m_rect.p3.x + alpha, m_rect.p3.y },            // p6
        { m_rect.p4.x - alpha, m_rect.p4.y },            // p7
        { m_rect.p4.x ,m_rect.p4.y + alpha }             // p8
    };
}

void StarObj::DrawStar()
{
    DrawLosange(m_losa);
    DrawRectangle(m_rect);
}

void StarObj::StarCollision(const StarObj *mob)
{
    float relativeAngle = RelativeAngle(mob->GetPosition(), this->GetPosition());

    if (relativeAngle > mob->GetOctCrit().p1 && relativeAngle <= mob->GetOctCrit().p2)
    {
        // 2 cas ici -> si T(vx) positif -> return {  vx, -vy }
        //              si T(vx) negatif -> return { -vx,  vy }
        Vector2 tmp5,tmp1,tmpv;
        tmpv = RotationTransform(this->GetVitesse(), Pi / 4.f);
        tmp5 = RotationTransform(this->GetOctogone().p5, Pi / 4.f);
        tmp1 = RotationTransform(mob->GetOctogone().p1, Pi / 4.f);

        if (tmp5.y < tmp1.y && tmpv.y < 0.f)
        {
            if (tmpv.x > 0.f)
                m_vitesse = Vector2 { std::sqrt((tmpv.x * tmpv.x) / 2.f), - std::sqrt((tmpv.x * tmpv.x) / 2.f) };
            else
                m_vitesse = Vector2 { - std::sqrt((tmpv.x * tmpv.x) / 2.f), std::sqrt((tmpv.x * tmpv.x) / 2.f) };
        }
    }
    else if(relativeAngle > mob->GetOctCrit().p2 && relativeAngle <= mob->GetOctCrit().p3)
    {
        if (this->GetOctogone().p6.y < mob->GetOctogone().p2.y && m_vitesse.y < 0.f)
            m_vitesse.y = 0.f;
    }
    else if(relativeAngle > mob->GetOctCrit().p3 && relativeAngle <= mob->GetOctCrit().p4)
    {
        // 2 cas ici -> si T(vy) positif -> return {  vx,  vy }
        //              si T(vy) negatif -> return { -vx, -vy }
        Vector2 tmp8,tmp4,tmpv;
        tmpv = RotationTransform(this->GetVitesse(), Pi / 4.f);
        tmp8 = RotationTransform(this->GetOctogone().p8, Pi / 4.f);
        tmp4 = RotationTransform(mob->GetOctogone().p4, Pi / 4.f);
        if (tmp8.x > tmp4.x && tmpv.x > 0.f)
        {
            if (tmpv.y > 0.f)
                m_vitesse = Vector2 { std::sqrt((tmpv.y * tmpv.y) / 2.f), std::sqrt((tmpv.y * tmpv.y) / 2.f) };
            else
                m_vitesse = Vector2 { - std::sqrt((tmpv.y * tmpv.y) / 2.f), - std::sqrt((tmpv.y * tmpv.y) / 2.f) };
        }
    }
    else if(relativeAngle > mob->GetOctCrit().p4 && relativeAngle <= mob->GetOctCrit().p5)
    {
        if (this->GetOctogone().p8.x > mob->GetOctogone().p5.x && m_vitesse.x > 0.f)
            m_vitesse.x = 0.f;
    }
    else if(relativeAngle > mob->GetOctCrit().p5 && relativeAngle <= mob->GetOctCrit().p6)
    {
        // 2 cas ici -> si T(vx) positif -> return {  vx, -vy }
        //              si T(vx) negatif -> return { -vx,  vy }
        Vector2 tmp1,tmp5,tmpv;
        tmpv = RotationTransform(this->GetVitesse(), Pi / 4.f);
        tmp1 = RotationTransform(this->GetOctogone().p1, Pi / 4.f);
        tmp5 = RotationTransform(mob->GetOctogone().p5, Pi / 4.f);
        if (tmp1.y > tmp5.y && tmpv.y > 0.f)
        {
            if (tmpv.x > 0.f)
                m_vitesse = Vector2 { std::sqrt((tmpv.x * tmpv.x) / 2.f), - std::sqrt((tmpv.x * tmpv.x) / 2.f) };
            else
                m_vitesse = Vector2 { - std::sqrt((tmpv.x * tmpv.x) / 2.f), std::sqrt((tmpv.x * tmpv.x) / 2.f) };
        }
    }
    else if(relativeAngle > mob->GetOctCrit().p6 && relativeAngle <= mob->GetOctCrit().p7)
    {
        if (this->GetOctogone().p3.y > mob->GetOctogone().p6.y && m_vitesse.y > 0.f)
            m_vitesse.y = 0.f;
    }
    else if(relativeAngle > mob->GetOctCrit().p7 && relativeAngle <= mob->GetOctCrit().p8)
    {
        // 2 cas ici -> si T(vy) positif -> return {  vx,  vy }
        //              si T(vy) negatif -> return { -vx, -vy }
        Vector2 tmp4,tmp7,tmpv;
        tmpv = RotationTransform(this->GetVitesse(), Pi / 4.f);
        tmp4 = RotationTransform(this->GetOctogone().p4, Pi / 4.f);
        tmp7 = RotationTransform(mob->GetOctogone().p7, Pi / 4.f);
        if (tmp4.x < tmp7.x && tmpv.x < 0.f)
        {
            if (tmpv.y > 0.f)
                m_vitesse = Vector2 {   std::sqrt((tmpv.y * tmpv.y) / 2.f),   std::sqrt((tmpv.y * tmpv.y) / 2.f) };
            else
                m_vitesse = Vector2 { - std::sqrt((tmpv.y * tmpv.y) / 2.f), - std::sqrt((tmpv.y * tmpv.y) / 2.f) };
        }
    }
    else if(relativeAngle > mob->GetOctCrit().p8 || relativeAngle <= mob->GetOctCrit().p1)
    {
        if (this->GetOctogone().p5.x < mob->GetOctogone().p8.x && m_vitesse.x < 0.f)
            m_vitesse.x = 0.f;
    }
}

void StarObj::OctogoneCollision(const OctogoneObj *oob)
{
    float relativeAngle = RelativeAngle(oob->GetPosition(), this->GetPosition());

    if (relativeAngle > oob->GetOctCrit().p1 && relativeAngle <= oob->GetOctCrit().p2)
    {
        // 2 cas ici -> si T(vx) positif -> return {  vx, -vy }
        //              si T(vx) negatif -> return { -vx,  vy }
        Vector2 tmp5,tmp1,tmpv;
        tmpv = RotationTransform(this->GetVitesse(), Pi / 4.f);
        tmp5 = RotationTransform(this->GetOctogone().p5, Pi / 4.f);
        tmp1 = RotationTransform(oob->GetOctogone().p1, Pi / 4.f);
        if (tmp5.y < tmp1.y && tmpv.y < 0.f)
        {
            if (tmpv.x > 0.f)
                m_vitesse = Vector2 { std::sqrt((tmpv.x * tmpv.x) / 2.f), - std::sqrt((tmpv.x * tmpv.x) / 2.f) };
            else
                m_vitesse = Vector2 { - std::sqrt((tmpv.x * tmpv.x) / 2.f), std::sqrt((tmpv.x * tmpv.x) / 2.f) };
        }
    }
    else if(relativeAngle > oob->GetOctCrit().p2 && relativeAngle <= oob->GetOctCrit().p3)
    {
        if (this->GetOctogone().p6.y < oob->GetOctogone().p2.y && m_vitesse.y < 0.f)
            m_vitesse.y = 0.f;
    }
    else if(relativeAngle > oob->GetOctCrit().p3 && relativeAngle <= oob->GetOctCrit().p4)
    {
        // 2 cas ici -> si T(vy) positif -> return {  vx,  vy }
        //              si T(vy) negatif -> return { -vx, -vy }
        Vector2 tmp8,tmp4,tmpv;
        tmpv = RotationTransform(this->GetVitesse(), Pi / 4.f);
        tmp8 = RotationTransform(this->GetOctogone().p8, Pi / 4.f);
        tmp4 = RotationTransform(oob->GetOctogone().p4, Pi / 4.f);
        if (tmp8.x > tmp4.x && tmpv.x > 0.f)
        {
            if (tmpv.y > 0.f)
                m_vitesse = Vector2 { std::sqrt((tmpv.y * tmpv.y) / 2.f), std::sqrt((tmpv.y * tmpv.y) / 2.f) };
            else
                m_vitesse = Vector2 { - std::sqrt((tmpv.y * tmpv.y) / 2.f), - std::sqrt((tmpv.y * tmpv.y) / 2.f) };
        }
    }
    else if(relativeAngle > oob->GetOctCrit().p4 && relativeAngle <= oob->GetOctCrit().p5)
    {
        if (this->GetOctogone().p8.x > oob->GetOctogone().p5.x && m_vitesse.x > 0.f)
            m_vitesse.x = 0.f;
    }
    else if(relativeAngle > oob->GetOctCrit().p5 && relativeAngle <= oob->GetOctCrit().p6)
    {
        // 2 cas ici -> si T(vx) positif -> return {  vx, -vy }
        //              si T(vx) negatif -> return { -vx,  vy }
        Vector2 tmp1,tmp5,tmpv;
        tmpv = RotationTransform(this->GetVitesse(), Pi / 4.f);
        tmp1 = RotationTransform(this->GetOctogone().p1, Pi / 4.f);
        tmp5 = RotationTransform(oob->GetOctogone().p5, Pi / 4.f);
        if (tmp1.y > tmp5.y && tmpv.y > 0.f)
        {
            if (tmpv.x > 0.f)
                m_vitesse = Vector2 { std::sqrt((tmpv.x * tmpv.x) / 2.f), - std::sqrt((tmpv.x * tmpv.x) / 2.f) };
            else
                m_vitesse = Vector2 { - std::sqrt((tmpv.x * tmpv.x) / 2.f), std::sqrt((tmpv.x * tmpv.x) / 2.f) };
        }
    }
    else if(relativeAngle > oob->GetOctCrit().p6 && relativeAngle <= oob->GetOctCrit().p7)
    {
        if (this->GetOctogone().p3.y > oob->GetOctogone().p6.y && m_vitesse.y > 0.f)
            m_vitesse.y = 0.f;
    }
    else if(relativeAngle > oob->GetOctCrit().p7 && relativeAngle <= oob->GetOctCrit().p8)
    {
        // 2 cas ici -> si T(vy) positif -> return {  vx,  vy }
        //              si T(vy) negatif -> return { -vx, -vy }
        Vector2 tmp4,tmp7,tmpv;
        tmpv = RotationTransform(this->GetVitesse(), Pi / 4.f);
        tmp4 = RotationTransform(this->GetOctogone().p4, Pi / 4.f);
        tmp7 = RotationTransform(oob->GetOctogone().p7, Pi / 4.f);
        if (tmp4.x < tmp7.x && tmpv.x < 0.f)
        {
            if (tmpv.y > 0.f)
                m_vitesse = Vector2 {   std::sqrt((tmpv.y * tmpv.y) / 2.f),   std::sqrt((tmpv.y * tmpv.y) / 2.f) };
            else
                m_vitesse = Vector2 { - std::sqrt((tmpv.y * tmpv.y) / 2.f), - std::sqrt((tmpv.y * tmpv.y) / 2.f) };
        }
    }
    else if(relativeAngle > oob->GetOctCrit().p8 || relativeAngle <= oob->GetOctCrit().p1)
    {
        if (this->GetOctogone().p5.x < oob->GetOctogone().p8.x && m_vitesse.x < 0.f)
            m_vitesse.x = 0.f;
    }
}

void StarObj::RectangleCollision(const RectangleObj *rob)
{

    float p1Rel = RelativeAngle(rob->GetPosition(), m_rect.p1);
    float p2Rel = RelativeAngle(rob->GetPosition(), m_rect.p2);
    float p3Rel = RelativeAngle(rob->GetPosition(), m_rect.p3);
    float p4Rel = RelativeAngle(rob->GetPosition(), m_rect.p4);

    if ((p3Rel > rob->GetRectCrit().p1 && p3Rel <= rob->GetRectCrit().p2) || (p4Rel > rob->GetRectCrit().p1 && p4Rel <= rob->GetRectCrit().p2))
    {
        if (this->GetRect().p3.y < rob->GetRect().p1.y && m_vitesse.y < 0.f)
            m_vitesse.y = 0.f;
    }
    else if ((p1Rel > rob->GetRectCrit().p2 && p1Rel <= rob->GetRectCrit().p3) || (p4Rel > rob->GetRectCrit().p2 && p4Rel <= rob->GetRectCrit().p3))
    {
        if (this->GetRect().p1.x > rob->GetRect().p3.x && m_vitesse.x > 0.f)
            m_vitesse.x = 0.f;
    }
    else if ((p1Rel > rob->GetRectCrit().p3 && p1Rel <= rob->GetRectCrit().p4) || (p2Rel > rob->GetRectCrit().p3 && p2Rel <= rob->GetRectCrit().p4))
    {
        if (this->GetRect().p1.y > rob->GetRect().p3.y && m_vitesse.y > 0.f)
            m_vitesse.y = 0.f;
    }
    else //if ((p2Rel > rob->GetRectCrit().p3 || p2Rel <= rob->GetRectCrit().p4) || (p3Rel > rob->GetRectCrit().p3 || p3Rel <= rob->GetRectCrit().p4))
    {
        if (this->GetRect().p3.x < rob->GetRect().p1.x && m_vitesse.x < 0.f)
            m_vitesse.x = 0.f;
    }
}

void StarObj::LosangeCollision(const LosangeObj *lob)
{
    float p1Rel = RelativeAngle(lob->GetPosition(), m_losa.p1);
    float p2Rel = RelativeAngle(lob->GetPosition(), m_losa.p2);
    float p3Rel = RelativeAngle(lob->GetPosition(), m_losa.p3);
    float p4Rel = RelativeAngle(lob->GetPosition(), m_losa.p4);

    if (lob->GetHeight() > lob->GetWidth())
    {
        if ((p3Rel > lob->GetCritLosa().p1 && p3Rel <= lob->GetCritLosa().p2) || (p4Rel > lob->GetCritLosa().p1 && p4Rel <= lob->GetCritLosa().p2))
        {
            Vector2 pTmp3, lTmp1, tmpv;
            pTmp3 = RotationTransform(m_losa.p3, Pi / 4.f);
            lTmp1 = RotationTransform(lob->GetLosa().p1, Pi / 4.f);
            tmpv = RotationTransform(this->GetVitesse(), Pi / 4.f);

            if (pTmp3.x > lTmp1.x && tmpv.x > 0)
            {
                if (tmpv.y > 0.f)
                    m_vitesse = Vector2 {  std::sqrt(tmpv.y * tmpv.y / 2.f),  std::sqrt(tmpv.y * tmpv.y / 2.f) };
                else
                    m_vitesse = Vector2 { -std::sqrt(tmpv.y * tmpv.y / 2.f), -std::sqrt(tmpv.y * tmpv.y / 2.f) };
            }
        }
        else if ((p1Rel > lob->GetCritLosa().p2 && p1Rel <= lob->GetCritLosa().p3) || (p4Rel > lob->GetCritLosa().p2 && p4Rel <= lob->GetCritLosa().p3))
        {
            Vector2 tmp1, tmp2, tmpv;
            tmp1 = RotationTransform(m_losa.p1, Pi / 4.f);
            tmp2 = RotationTransform(lob->GetLosa().p2, Pi / 4.f);
            tmpv = RotationTransform(this->GetVitesse(), Pi / 4.f);

            if (tmp1.y > tmp2.y && tmpv.y > 0.f)
            {
                if (tmpv.x > 0.f)
                    m_vitesse = Vector2 {  std::sqrt(tmpv.x * tmpv.x / 2.f), -std::sqrt(tmpv.x * tmpv.x / 2.f) };
                else
                    m_vitesse = Vector2 { -std::sqrt(tmpv.x * tmpv.x / 2.f),  std::sqrt(tmpv.x * tmpv.x / 2.f) };
            }
        }
        else if ((p1Rel > lob->GetCritLosa().p3 && p1Rel <= lob->GetCritLosa().p4) || (p2Rel > lob->GetCritLosa().p3 && p2Rel <= lob->GetCritLosa().p4))
        {
            Vector2 tmp1, tmp3, tmpv;
            tmp1 = RotationTransform(m_losa.p1, Pi / 4.f);
            tmp3 = RotationTransform(lob->GetLosa().p3, Pi / 4.f);
            tmpv = RotationTransform(this->GetVitesse(), Pi / 4.f);

            if (tmp1.x < tmp3.x && tmpv.x < 0.f)
            {
                if (tmpv.y > 0.f)
                    m_vitesse = Vector2 {  std::sqrt(tmpv.y * tmpv.y / 2.f),  std::sqrt(tmpv.y * tmpv.y / 2.f) };
                else
                    m_vitesse = Vector2 { -std::sqrt(tmpv.y * tmpv.y / 2.f), -std::sqrt(tmpv.y * tmpv.y / 2.f) };
            }
        }
        else
        {
            Vector2 tmp1, tmp2, tmpv;
            tmp1 = RotationTransform(lob->GetLosa().p1, Pi / 4.f);
            tmp2 = RotationTransform(m_losa.p2, Pi / 4.f);
            tmpv = RotationTransform(this->GetVitesse(), Pi / 4.f);

            if (tmp2.y < tmp1.y && tmpv.y < 0.f)
            {
                if (tmpv.x > 0.f)
                    m_vitesse = Vector2 {  std::sqrt(tmpv.x * tmpv.x / 2.f), -std::sqrt(tmpv.x * tmpv.x / 2.f) };
                else
                    m_vitesse = Vector2 { -std::sqrt(tmpv.x * tmpv.x / 2.f),  std::sqrt(tmpv.x * tmpv.x / 2.f) };

            }
        }
    }
    else
    {
        if ((p3Rel > lob->GetCritLosa().p1 && p3Rel <= lob->GetCritLosa().p2) || (p4Rel > lob->GetCritLosa().p1 && p4Rel <= lob->GetCritLosa().p2))
        {
            Vector2 pTmp3, lTmp1, tmpv;
            pTmp3 = RotationTransform(m_losa.p3, Pi / 4.f);
            lTmp1 = RotationTransform(lob->GetLosa().p1, Pi / 4.f);
            tmpv = RotationTransform(this->GetVitesse(), Pi / 4.f);

            if (pTmp3.x > lTmp1.x && tmpv.x > 0)
            {
                if (tmpv.y > 0.f)
                    m_vitesse = Vector2 {  std::sqrt(tmpv.y * tmpv.y / 2.f),  std::sqrt(tmpv.y * tmpv.y / 2.f) };
                else
                    m_vitesse = Vector2 { -std::sqrt(tmpv.y * tmpv.y / 2.f), -std::sqrt(tmpv.y * tmpv.y / 2.f) };
            }
        }
        else if ((p1Rel > lob->GetCritLosa().p2 && p1Rel <= lob->GetCritLosa().p3) || (p4Rel > lob->GetCritLosa().p2 && p4Rel <= lob->GetCritLosa().p3))
        {
            Vector2 tmp1, tmp2, tmpv;
            tmp1 = RotationTransform(m_losa.p1, Pi / 4.f);
            tmp2 = RotationTransform(lob->GetLosa().p2, Pi / 4.f);
            tmpv = RotationTransform(this->GetVitesse(), Pi / 4.f);

            if (tmp1.y > tmp2.y && tmpv.y > 0.f)
            {
                if (tmpv.x > 0.f)
                    m_vitesse = Vector2 {  std::sqrt(tmpv.x * tmpv.x / 2.f), -std::sqrt(tmpv.x * tmpv.x / 2.f) };
                else
                    m_vitesse = Vector2 { -std::sqrt(tmpv.x * tmpv.x / 2.f),  std::sqrt(tmpv.x * tmpv.x / 2.f) };
            }
        }
        else if ((p2Rel > lob->GetCritLosa().p4 && p2Rel <= lob->GetCritLosa().p1) || (p3Rel > lob->GetCritLosa().p4 && p3Rel <= lob->GetCritLosa().p1))
        {
            Vector2 tmp1, tmp2, tmpv;
            tmp1 = RotationTransform(lob->GetLosa().p1, Pi / 4.f);
            tmp2 = RotationTransform(m_losa.p2, Pi / 4.f);
            tmpv = RotationTransform(this->GetVitesse(), Pi / 4.f);

            if (tmp2.y < tmp1.y && tmpv.y < 0.f)
            {
                if (tmpv.x > 0.f)
                    m_vitesse = Vector2 {  std::sqrt(tmpv.x * tmpv.x / 2.f), -std::sqrt(tmpv.x * tmpv.x / 2.f) };
                else
                    m_vitesse = Vector2 { -std::sqrt(tmpv.x * tmpv.x / 2.f),  std::sqrt(tmpv.x * tmpv.x / 2.f) };

            }
        }
        else
        {
            Vector2 tmp1, tmp3, tmpv;
            tmp1 = RotationTransform(m_losa.p1, Pi / 4.f);
            tmp3 = RotationTransform(lob->GetLosa().p3, Pi / 4.f);
            tmpv = RotationTransform(this->GetVitesse(), Pi / 4.f);

            if (tmp1.x < tmp3.x && tmpv.x < 0.f)
            {
                if (tmpv.y > 0.f)
                    m_vitesse = Vector2 {  std::sqrt(tmpv.y * tmpv.y / 2.f),  std::sqrt(tmpv.y * tmpv.y / 2.f) };
                else
                    m_vitesse = Vector2 { -std::sqrt(tmpv.y * tmpv.y / 2.f), -std::sqrt(tmpv.y * tmpv.y / 2.f) };
            }
        }
    }
}

