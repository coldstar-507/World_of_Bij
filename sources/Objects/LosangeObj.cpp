#include "LosangeObj.h"
#include <cmath>
#include "Core/Draw.h"

LosangeObj::LosangeObj(Vector2 p_position, std::string p_textureID, float p_angle, float p_width, float p_height)
    : Entity(p_position, p_textureID, p_angle), m_width(p_width), m_height(p_height)
{
    m_center = { p_width / 2.f , p_height / 2.f };

    Quad tmpRect = {
        m_position + m_center,                                            //p1
        { m_position.x - m_center.x, m_position.y + m_center.y },         //p2
        m_position - m_center,                                            //p3
        { m_position.x + m_center.x, m_position.y - m_center.y }          //p4
    };

    m_losa = {
        m_position + RotationTransform(tmpRect.p1 - m_position, Pi / 4.f),
        m_position + RotationTransform(tmpRect.p2 - m_position, Pi / 4.f),
        m_position + RotationTransform(tmpRect.p3 - m_position, Pi / 4.f),
        m_position + RotationTransform(tmpRect.p4 - m_position, Pi / 4.f)
    };

    float angleImportant = std::atan(m_height / m_width);

    CriticalAngles tmpCrit = {
        (2.f * Pi) - angleImportant,
        angleImportant,
        Pi - angleImportant,
        Pi + angleImportant
    };

    m_losaCrit = {
        tmpCrit.p1 += Pi / 4.f,
        tmpCrit.p2 += Pi / 4.f,
        tmpCrit.p3 += Pi / 4.f,
        tmpCrit.p4 += Pi / 4.f
    };

    if (m_width > m_height)
        m_rayon = m_height / 2.f;
    else
        m_rayon = m_width / 2.f;

    m_bigRayon = Distance(m_losa.p1, m_losa.p3) / 2.f;
}

void LosangeObj::DrawLosa()
{
    DrawLosange(m_losa);
}

void LosangeObj::UpdateRectPosition()
{
    Quad tmpRect = {
        m_position + m_center,                                            //p1
        { m_position.x - m_center.x, m_position.y + m_center.y },         //p2
        m_position - m_center,                                            //p3
        { m_position.x + m_center.x, m_position.y - m_center.y }          //p4
    };

    m_losa = {
        m_position + RotationTransform(tmpRect.p1 - m_position, Pi / 4.f),
        m_position + RotationTransform(tmpRect.p2 - m_position, Pi / 4.f),
        m_position + RotationTransform(tmpRect.p3 - m_position, Pi / 4.f),
        m_position + RotationTransform(tmpRect.p4 - m_position, Pi / 4.f)
    };
}
