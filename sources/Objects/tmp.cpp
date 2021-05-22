//
// Created by scott on 4/1/2021.
//

#include "MovingObject.h"
#include <cmath>
#include "Texture/TextureBank.h"
#include "meta.h"

MovingObject::MovingObject(Vector2 p_position, std::string p_textureID, float p_acc, int p_speedLevels)
    : SolideObject(p_position, p_textureID), m_slow(false), m_movingDown(false), m_movingUp(false),
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

void MovingObject::MovementRoutine(const std::vector<SolideObject*> & p_sov)
{
    UpMove();
    DownMove();
    LeftStrafe();
    RightStrafe();
    CalculateVitesse();
    CheckCollisions(p_sov); // This function will call CalculateCollision if theres a 'possible' collision
    ApplyVitesse();
    UpdateHitBoxPosition();
    UpdateTexturePosition();
}

void MovingObject::CheckCollisions(const std::vector<SolideObject*> & p_sov)
{
    for (auto & so : p_sov)
    {
        if (Distance(so->GetPosition(), this->GetPosition()) <= so->GetBigRayon() + this->GetBigRayon() && so->GetUniqueID() != this->GetUniqueID())
            this->CalculateCollision(so);
    }
}

void MovingObject::CalculateCollision(const SolideObject* p_so)
{
    float relativeAngle = RelativeAngle(p_so->GetPosition(), this->GetPosition());

    if (this->GetHitBox().p2.x < p_so->GetHitBox().p1.x
        && (relativeAngle > p_so->GetCriticalAngles().p4 || relativeAngle < p_so->GetCriticalAngles().p1) && m_vitesse.x < 0.f)
        m_vitesse.x = 0.f;

    else if (this->GetHitBox().p3.y < p_so->GetHitBox().p1.y
             && (relativeAngle > p_so->GetCriticalAngles().p1 && relativeAngle < p_so->GetCriticalAngles().p2) && m_vitesse.y < 0.f)
        m_vitesse.y = 0.f;

    else if (this->GetHitBox().p1.x > p_so->GetHitBox().p3.x
             && (relativeAngle > p_so->GetCriticalAngles().p2 && relativeAngle < p_so->GetCriticalAngles().p3) && m_vitesse.x > 0.f)
        m_vitesse.x = 0.f;

    else if (this->GetHitBox().p1.y > p_so->GetHitBox().p3.y
             && (relativeAngle > p_so->GetCriticalAngles().p3 && relativeAngle < p_so->GetCriticalAngles().p4) && m_vitesse.y > 0.f)
        m_vitesse.y = 0.f;
}

void MovingObject::CalculateVitesse()
{
    m_vitesse.x = *m_up   * std::cos(m_angle)
                - *m_down * std::cos(m_angle)
                + *m_sl   * std::cos(m_angle - M_PI / 2)
                + *m_sr   * std::cos(m_angle + M_PI / 2);

    m_vitesse.y = *m_up   * std::sin(m_angle)
                - *m_down * std::sin(m_angle)
                + *m_sl   * std::sin(m_angle - M_PI / 2)
                + *m_sr   * std::sin(m_angle + M_PI / 2);
}

void MovingObject::ApplyVitesse()
{
    m_position += m_vitesse;
}

void MovingObject::UpMove()
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

void MovingObject::DownMove()
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

void MovingObject::LeftStrafe()
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

void MovingObject::RightStrafe()
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

void MovingObject::TurnLeft()
{

}

void MovingObject::TurnRight()
{

}

void MovingObject::UpdateTexturePosition()
{
    m_texturePosition.x = m_position.x - TextureBank::GetTexture(GetTextureID())->GetWidth() / 2;
    m_texturePosition.y = m_position.y - TextureBank::GetTexture(GetTextureID())->GetHeight() / 2;
}

void MovingObject::UpdateHitBoxPosition()
{
    m_hitBox.p3 = m_texturePosition;
    m_hitBox.p4.x = m_texturePosition.x + (float) TextureBank::GetTexture(GetTextureID())->GetWidth();
    m_hitBox.p4.y = m_texturePosition.y;
    m_hitBox.p1.x = m_hitBox.p4.x;
    m_hitBox.p1.y = m_hitBox.p4.y + (float) TextureBank::GetTexture(GetTextureID())->GetHeight();
    m_hitBox.p2.x = m_hitBox.p3.x;
    m_hitBox.p2.y = m_hitBox.p1.y;
}
