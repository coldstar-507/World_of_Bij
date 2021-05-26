#include "OctogoneObj.h"
#include "Core/Draw.h"

OctogoneObj::OctogoneObj(Vector2 p_position, std::string p_textureID, float p_angle, float p_diametre)
    : Entity(p_position, p_textureID, p_angle), m_diametre(p_diametre)
{    
    m_rayon = p_diametre / 2.f;

    float beta = 0.414f * m_diametre;
    float alpha = (m_diametre - beta) / 2.f;

    Quad tmpQuad = {
        m_position + Vector2 {  m_rayon,  m_rayon },                      //p1
        m_position + Vector2 { -m_rayon,  m_rayon },                      //p2
        m_position + Vector2 { -m_rayon, -m_rayon },                      //p3
        m_position + Vector2 {  m_rayon, -m_rayon }                       //p4
    };

    m_oct = {
        { tmpQuad.p1.x, tmpQuad.p1.y - alpha },            // p1
        { tmpQuad.p1.x - alpha, tmpQuad.p1.y },            // p2
        { tmpQuad.p2.x + alpha, tmpQuad.p1.y },            // p3
        { tmpQuad.p2.x, tmpQuad.p2.y - alpha },            // p4
        { tmpQuad.p2.x, tmpQuad.p3.y + alpha },            // p5
        { tmpQuad.p3.x + alpha, tmpQuad.p3.y },            // p6
        { tmpQuad.p4.x - alpha, tmpQuad.p4.y },            // p7
        { tmpQuad.p4.x, tmpQuad.p4.y + alpha }             // p8
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

    m_bigRayon = Distance(m_oct.p1, m_oct.p5) / 2.f;
}

void OctogoneObj::UpdateOctPosition()
{
    float beta = 0.414f * m_diametre;
    float alpha = (m_diametre - beta) / 2.f;

    Quad tmpQuad = {
        m_position + Vector2 {  m_rayon,  m_rayon },                      //p1
        m_position + Vector2 { -m_rayon,  m_rayon },                      //p2
        m_position + Vector2 { -m_rayon, -m_rayon },                      //p3
        m_position + Vector2 {  m_rayon, -m_rayon }                       //p4
    };
    m_oct = {
        { tmpQuad.p1.x, tmpQuad.p1.y - alpha },            // p1
        { tmpQuad.p1.x - alpha, tmpQuad.p1.y },            // p2
        { tmpQuad.p2.x + alpha, tmpQuad.p1.y },            // p3
        { tmpQuad.p2.x, tmpQuad.p2.y - alpha },            // p4
        { tmpQuad.p2.x, tmpQuad.p3.y + alpha },            // p5
        { tmpQuad.p3.x + alpha, tmpQuad.p3.y },            // p6
        { tmpQuad.p4.x - alpha, tmpQuad.p4.y },            // p7
        { tmpQuad.p4.x, tmpQuad.p4.y + alpha }             // p8
    };
}

void OctogoneObj::DrawOct()
{
    DrawOctogone(m_oct);
}
