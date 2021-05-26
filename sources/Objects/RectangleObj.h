//
// Created by scott on 4/1/2021.
//

#ifndef WOB_OBJECT_H
#define WOB_OBJECT_H

#include "Entity.h"

class RectangleObj : public Entity
{
public:
    RectangleObj(Vector2 p_position, std::string p_textureID, float p_angle, float p_width, float p_height);
    ~RectangleObj() = default;
protected: // These don't change once initialized
    float m_width, m_height;
    Vector2 m_center;
    CriticalAngles m_rectCrit;
    Quad m_rect;                        //  p3--p4
                                        //  |    |
                                        //  p2--p1
public:
    Quad GetRect() const { return m_rect; }
    CriticalAngles GetRectCrit() const { return m_rectCrit; }
    float GetWidth() const { return m_width; }
    float GetHeight() const { return m_height; }
public:
    void UpdateRectPosition();
    void DrawRect();
};


#endif //WOB_OBJECT_H
