#include "MovingObj.h"
#include "Texture/TextureBank.h"

MovingObj::MovingObj(Vector2 p_position, std::string p_textureID, float p_angle, float p_diametre, float p_acc, int p_speedLevels)
    : StarObj(p_position, p_textureID, p_angle, p_diametre), m_slow(false), m_movingDown(false), m_movingUp(false),
                                              m_strafingLeft(false), m_strafingRight(false)
{
    // On initialise le grandeur des speed vectors
    m_upSpeed.resize(p_speedLevels);
    m_downSpeed.resize(p_speedLevels);
    m_strafeLeftSpeed.resize(p_speedLevels);
    m_strafeRightSpeed.resize(p_speedLevels);
    // On initialise les iterateurs de speed vectors
    // Deux iterateurs constant de debut et de fin pour chaque
    // Un de plus pour la moitier de vitesse (shift walk)
    // Puis un iterateur qui se promene entre eux, celui qui va representer la vitesse
    for (int i = 0; i < p_speedLevels; i++)
    {
        m_upSpeed[i] = i * p_acc;
        m_downSpeed[i] = i * (p_acc / 2.f);
        m_strafeLeftSpeed[i] = i * (p_acc / 1.33f);
        m_strafeRightSpeed[i] = i * (p_acc / 1.33f);
    }
    m_upFst = m_upSpeed.cbegin();
    m_upLst = std::prev(m_upSpeed.cend());
    m_upSlw = m_upSpeed.cbegin() + (p_speedLevels / 2);
    m_downFst = m_downSpeed.cbegin();
    m_downLst = std::prev(m_downSpeed.cend());
    m_downSlw = m_downFst + (p_speedLevels / 2);
    m_slFst = m_strafeLeftSpeed.cbegin();
    m_slLst = std::prev(m_strafeLeftSpeed.cend());
    m_slSlw = m_slFst + (p_speedLevels / 2);
    m_srFst = m_strafeRightSpeed.cbegin();
    m_srLst = std::prev(m_strafeRightSpeed.cend());
    m_srSlw = m_srFst + (p_speedLevels / 2);
    m_up = m_upSpeed.begin();
    m_down = m_downSpeed.begin();
    m_sl = m_strafeLeftSpeed.begin();
    m_sr = m_strafeRightSpeed.begin();
}

void MovingObj::UpdatePositions() // reprend pratiquement le constructeurs, appeler lorque changement de postition
{                                 // qui n'est pas relier a la vitesse
    this->UpdateTexturePosition();
    this->UpdateStarPositions();
}

void MovingObj::MovementRoutine(const std::vector<OctogoneObj*> & p_oov,
                                const std::vector<RectangleObj*> & p_rov,
                                const std::vector<LosangeObj*> & p_lov,
                                const std::vector<MovingObj*> & p_mov)
{
    UpMove();
    DownMove();
    LeftStrafe();
    RightStrafe();
    CalculateVitesse();
    CheckCollisions(p_oov, p_rov, p_lov, p_mov); // This function will call CalculateCollision if theres a 'possible' collision
    ApplyVitesse();
}

void MovingObj::CheckCollisions(const std::vector<OctogoneObj*> & p_oov,
                                const std::vector<RectangleObj*> & p_rov,
                                const std::vector<LosangeObj*> & p_lov,
                                const std::vector<MovingObj*> & p_mov)
{
    for (auto & so : p_mov)
    {
        if (Distance(so->GetPosition(), this->GetPosition()) <= so->GetBigRayon() + this->GetBigRayon() && GetUniqueID() != so->GetUniqueID())
            this->StarCollision(so);
    }
    for (auto & oo : p_oov)
    {
        if (Distance(oo->GetPosition(), this->GetPosition()) <= oo->GetBigRayon() + this->GetBigRayon())
            this->OctogoneCollision(oo);
    }
    for (auto & ro : p_rov)
    {
        if (Distance(ro->GetPosition(), this->GetPosition()) <= ro->GetBigRayon() + this->GetBigRayon())
            this->RectangleCollision(ro);
    }
    for (auto & lo : p_lov)
    {
        if (Distance(lo->GetPosition(), this->GetPosition()) <= lo->GetBigRayon() + this->GetBigRayon())
            this->LosangeCollision(lo);
    }
}

void MovingObj::CalculateVitesse()
{
    m_vitesse.x = *m_up   * std::cos(m_angle)
                - *m_down * std::cos(m_angle)
                + *m_sl   * std::cos(m_angle - Pi / 2)
                + *m_sr   * std::cos(m_angle + Pi / 2);

    m_vitesse.y = *m_up   * std::sin(m_angle)
                - *m_down * std::sin(m_angle)
                + *m_sl   * std::sin(m_angle - Pi / 2)
                + *m_sr   * std::sin(m_angle + Pi / 2);
}

void MovingObj::ApplyVitesse()
{
    m_position += m_vitesse;

    m_texturePosition += m_vitesse;

    m_rect.p1 += m_vitesse;
    m_rect.p2 += m_vitesse;
    m_rect.p3 += m_vitesse;
    m_rect.p4 += m_vitesse;

    m_losa.p1 += m_vitesse;
    m_losa.p2 += m_vitesse;
    m_losa.p3 += m_vitesse;
    m_losa.p4 += m_vitesse;

    m_oct.p1 += m_vitesse;
    m_oct.p2 += m_vitesse;
    m_oct.p3 += m_vitesse;
    m_oct.p4 += m_vitesse;
    m_oct.p5 += m_vitesse;
    m_oct.p6 += m_vitesse;
    m_oct.p7 += m_vitesse;
    m_oct.p8 += m_vitesse;
}

void MovingObj::UpMove()
{
    if (m_slow && m_movingUp)
    {
        if (m_up > m_upSlw)
            m_up--;
        else if (m_up < m_upSlw)
            m_up++;
    }
    else if (m_movingUp)
    {
        if (m_up < m_upLst)
            m_up++;
    }
    else
    {
        if (m_up > m_upFst)
            m_up--;
    }
}

void MovingObj::DownMove()
{
    if (m_slow && m_movingDown)
    {
        if (m_down > m_downSlw)
            m_down--;
        else if (m_down < m_downSlw)
            m_down++;
    }
    else if (m_movingDown)
    {
        if (m_down < m_downLst)
            m_down++;
    }
    else
    {
        if (m_down > m_downFst)
            m_down--;
    }
}

void MovingObj::LeftStrafe()
{
    if (m_slow && m_strafingLeft)
    {
        if (m_sl > m_slSlw)
            m_sl--;
        else if (m_sl < m_slSlw)
            m_sl++;
    }
    else if (m_strafingLeft)
    {
        if (m_sl < m_slLst)
            m_sl++;
    }
    else
    {
        if (m_sl > m_slFst)
            m_sl--;
    }
}

void MovingObj::RightStrafe()
{
    if (m_slow && m_strafingRight)
    {
        if (*m_sr > *m_srSlw)
            m_sr--;
        else if (*m_sr < *m_srSlw)
            m_sr++;
    }
    else if (m_strafingRight)
    {
        if (*m_sr < *m_srLst)
            m_sr++;
    }
    else
    {
        if (*m_sr > *m_srFst)
            m_sr--;
    }
}

void MovingObj::TurnLeft()
{
    ;
}

void MovingObj::TurnRight()
{
    ;
}

