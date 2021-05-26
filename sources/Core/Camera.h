//
// Created by scott on 4/1/2021.
//

#ifndef WOB_CAMERA_H
#define WOB_CAMERA_H

#include "2DPhysics/Math.h"
#include "SDL.h"
#include "meta.h"
#include <cmath>


class Camera
{
public:
    static void Init(Vector2* p_position);
    static Vector2 Position() { return *m_position; }
    static float CurrentZoom() { return m_zoom; }
    static Vector2 Center() { return m_center; }
    static Vector2 UpperCorner() { return m_upperLeftCornerPosition;}

    static void Update() { m_upperLeftCornerPosition = *m_position - m_center; }
    static void Move(Vector2 p_vec) { m_position->x += p_vec.x; m_position->y += p_vec.y; }
    static void Rotate(float p_angle) {  m_angle += p_angle; }
    static void Zoom(float p_zoom) {  m_zoom *= p_zoom; }
    static float TransformX(float p_x) { return (( p_x - m_position->x ) * m_zoom ) + m_center.x; }
    static float TransformY(float p_y) { return (( p_y - m_position->y ) * m_zoom ) + m_center.y; }
    static Vector2 TransformV(Vector2 p_v) { return { TransformX(p_v.x) , TransformY(p_v.y) } ; }

private:
    Camera() = default;
    static Vector2*  m_position;
    static const Vector2 m_center;
    static Vector2 m_upperLeftCornerPosition;
    static float m_angle;
    static float m_zoom;
};


#endif //WOB_CAMERA_H
