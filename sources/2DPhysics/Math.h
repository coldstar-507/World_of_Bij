//
// Created by scott on 4/1/2021.
//
#ifndef WOB_MATH_H
#define WOB_MATH_H

#include <iostream>

constexpr float Pi = 3.14159265359f;

struct Vector2
{
    float x, y; // float masterrace

    Vector2 operator()(float p_x, float p_y)
    {
        return {p_x, p_y };
    }

    Vector2 operator+(Vector2 v)
    {
        return {x + v.x, y + v.y};
    }

    Vector2 operator-(Vector2 v)
    {
        return { x - v.x, y - v.y };
    }

    Vector2 operator+=(Vector2 v)
    {
        return { x += v.x, y += v.y };
    }

    Vector2 operator-=(Vector2 v)
    {
        return { x -= v.x , y -= v.y };
    }

    bool operator==(Vector2 v)
    {
        return (x == v.x && y == v.y);
    }

    bool operator!=(Vector2 v)
    {
        return (x != v.x || y != v.y);
    }

    float Normal();
};

struct Quad
{
    Vector2 p1, p2, p3, p4;
};

struct Octogone
{
    Vector2 p1, p2, p3, p4, p5, p6, p7, p8;
};

struct OctCriticalAngles
{
    float p1, p2, p3, p4, p5, p6, p7, p8;
};

struct CriticalAngles
{
    float p1, p2, p3, p4;
};

float RadToDeg(float p_rad);


float DegToRad(float p_deg);


float Distance(const Vector2& p1, const Vector2& p2);

float NormalizeRad(float rad);

// L'angle calculer est celui de p1
// Donc pour la collision, il est plus facile de calculer le "relative angle"
// de l'objet avec lequel on entre en collision
float RelativeAngle(const Vector2& p1, const Vector2& p2);

Vector2 RotationTransform(const Vector2& p, float angle);

Vector2 RandomPoint();

#endif //WOB1_MATH_H
