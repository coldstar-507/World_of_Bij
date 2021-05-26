#include "Player.h"
#include "Core/Camera.h"
#include "Core/Draw.h"

Player::Player(Vector2 p_position, std::string p_textureID, float p_angle, float p_diametre, float p_acc, int p_speedLevels)
    : MovingObj(p_position, p_textureID, p_angle, p_diametre, p_acc, p_speedLevels)
{
    m_monsterTargetBuffer.resize(25);

    m_targetDots[0].distance = 100.0f;
    m_targetDots[1].distance = 280.0f;
    m_targetDots[2].distance = 550.0f;
    m_targetDots[0].position.x = m_position.x + m_targetDots[0].distance * std::cos(m_angle);
    m_targetDots[0].position.y = m_position.y + m_targetDots[0].distance * std::sin(m_angle);
    m_targetDots[1].position.x = m_position.x + m_targetDots[1].distance * std::cos(m_angle);
    m_targetDots[1].position.y = m_position.y + m_targetDots[1].distance * std::sin(m_angle);
    m_targetDots[2].position.x = m_position.x + m_targetDots[2].distance * std::cos(m_angle);
    m_targetDots[2].position.y = m_position.y + m_targetDots[2].distance * std::sin(m_angle);
    m_targetDots[0].rayon = Distance(m_position, m_targetDots[0].position);
    m_targetDots[1].rayon = Distance(m_targetDots[0].position, m_targetDots[1].position);
    m_targetDots[2].rayon = Distance(m_targetDots[1].position, m_targetDots[2].position);
}

void Player::TargetMonsters(const std::vector<Monsters*> & p_mv)
{
    int k = 0;
    int l = 0;

    for (int i = 0; i < 3; i++) // 3 signifie le nombre de targetdots
    {
        for (auto & monster : p_mv)
        {
            if (Distance(monster->GetPosition(), this->m_targetDots[i].position) < this->m_targetDots[i].rayon)
            {
                m_monsterTargetBuffer[k] = monster;
                k++;
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (!m_monsterTargetBuffer[i]->m_targeted)
        {
            m_monsterTarget = m_monsterTargetBuffer[i];
            m_monsterTargetBuffer[i]->m_targeted = true;
            break;
        }
        else
        {
            l++;
        }
    }
    if (l == k)
    {
        for (int i = 0; i < k; i++)
        {
            m_monsterTargetBuffer[i]->m_targeted = false;
        }
        m_monsterTarget = m_monsterTargetBuffer[0];
        if (m_monsterTarget)
        {
            m_monsterTarget->m_targeted = true;
        }
    }
}

void Player::DrawMonsterTarget()
{
    if (m_monsterTarget)
        Draw("targetcircle", m_monsterTarget->GetTexturePosition());
}


void Player::MovementRoutine(const std::vector<OctogoneObj*> & p_oov, const std::vector<RectangleObj*> & p_rov,
                             const std::vector<LosangeObj*> & p_lov, const std::vector<MovingObj*> & p_mov)
{
    UpMove();
    DownMove();
    LeftStrafe();
    RightStrafe();
    CalculateMousePosition();
    CalculateAngleFromMouse();
    CalculateVitesse();
    CheckCollisions(p_oov, p_rov, p_lov, p_mov);
    ApplyVitesse();
    UpdateTargetDotsPositions();
}

void Player::ApplyVitesse()
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

void Player::UpdateTargetDotsPositions()
{
    m_targetDots[0].position.x = m_position.x + m_targetDots[0].distance * std::cos(m_angle);
    m_targetDots[0].position.y = m_position.y + m_targetDots[0].distance * std::sin(m_angle);
    m_targetDots[1].position.x = m_position.x + m_targetDots[1].distance * std::cos(m_angle);
    m_targetDots[1].position.y = m_position.y + m_targetDots[1].distance * std::sin(m_angle);
    m_targetDots[2].position.x = m_position.x + m_targetDots[2].distance * std::cos(m_angle);
    m_targetDots[2].position.y = m_position.y + m_targetDots[2].distance * std::sin(m_angle);
}


void Player::CalculateMousePosition()
{
    m_mousePosition = Camera::UpperCorner() + Vector2 { (float) m_mouseX, (float) m_mouseY };
}

void Player::CalculateAngleFromMouse()
{
    if (Distance(GetPosition(), m_mousePosition) > 0.01f) // sinon on peu pete le jeu
        m_angle = RelativeAngle(GetPosition(), m_mousePosition);
}

void Player::DrawTargetCircles()
{
    for (auto & c : m_targetDots)
        DrawCircle(c.position, c.rayon);
}
