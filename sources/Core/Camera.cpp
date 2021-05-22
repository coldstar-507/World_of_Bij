//
// Created by scott on 4/1/2021.
//

#include "Camera.h"
#include "meta.h"

Vector2* Camera::m_position;
const Vector2 Camera::m_center = { (float) WINDOW_SIZE_X / 2.f, (float) WINDOW_SIZE_Y / 2.f };
float Camera::m_angle;
float Camera::m_zoom;
Vector2 Camera::m_upperLeftCornerPosition;

void Camera::Init(Vector2 *p_position)
{
    m_position = p_position;
    m_upperLeftCornerPosition = *m_position - m_center;
    m_angle = 0.f;
    m_zoom = 1.f;
}
