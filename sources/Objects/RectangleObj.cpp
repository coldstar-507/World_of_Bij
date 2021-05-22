//
// Created by scott on 4/1/2021.
//

#include "RectangleObj.h"
#include "Core/Drawer.h"

RectangleObj::RectangleObj(Vector2 p_position, std::string p_textureID, float p_angle, float p_width, float p_height)
    : Entity(p_position, p_textureID, p_angle), m_width(p_width), m_height(p_height)
{
    m_center = { m_width / 2.f , m_height / 2.f };
    m_rect = {
        m_position + m_center,                                            //p1
        { m_position.x - m_center.x, m_position.y + m_center.y },         //p2
        m_position - m_center,                                            //p3
        { m_position.x + m_center.x, m_position.y - m_center.y }          //p4
    };

    float angleImportant = std::atan(m_height / m_width);
    m_rectCrit = {
        angleImportant,
        M_PIf32 - angleImportant,
        M_PIf32 + angleImportant,
        (2.f * M_PIf32) - angleImportant
    };

    if (m_width > m_height)
        m_rayon = m_height / 2.f;
    else
        m_rayon = m_width / 2.f;

    m_bigRayon = Distance(m_rect.p1, m_rect.p3) / 2.f;
}

void RectangleObj::DrawRect()
{
    DrawRectangle(m_rect);
}

void RectangleObj::UpdateRectPosition()
{
    m_rect = {
        m_position + m_center,                                            //p1
        { m_position.x - m_center.x, m_position.y + m_center.y },         //p2
        m_position - m_center,                                            //p3
        { m_position.x + m_center.x, m_position.y - m_center.y }          //p4
    };
}

