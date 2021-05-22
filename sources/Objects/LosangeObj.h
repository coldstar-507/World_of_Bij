#ifndef LOSANGE_H
#define LOSANGE_H

// Un rectangle avec un 45degree rotation transform;

#include "RectangleObj.h"

class LosangeObj : public Entity
{
public:
    LosangeObj(Vector2 p_position, std::string p_textureID, float p_angle, float p_width, float p_height);
    ~LosangeObj() = default;
private:
    Quad m_losa;
    Vector2 m_center;
    CriticalAngles m_losaCrit;
    float m_width, m_height;
public:
    Quad GetLosa() const { return m_losa; }
    CriticalAngles GetCritLosa() const { return m_losaCrit; }
    void UpdateRectPosition();
    void DrawLosa();
};

#endif // LOSANGE_H
