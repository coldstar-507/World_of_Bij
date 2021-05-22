//
// Created by scott on 4/1/2021.
//
#ifndef WOB1_MATH_H
#define WOB1_MATH_H

#include <iostream>


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


// L'angle calculer est celui de p1
// Donc pour la collision, il est plus facile de calculer le "relative angle"
// de l'objet avec lequel on entre en collision
float RelativeAngle(const Vector2& p1, const Vector2& p2);

Vector2 RotationTransform(const Vector2& p, float angle);

Vector2 RandomPoint();

void PrintV2(const Vector2 & v, const char* msg);


class Loger
{
private:
    Loger() = default;
    ~Loger() = default;
    static int i;
public:
    static void logi() { std::cout << "LOGER : " << i << std::endl; i++; }
    static void resetLogi() { i = 0; }

    template <typename T2>
    static void log(T2 msg) { std::cout << "LOGER : " << msg << std::endl; }


};

#endif //WOB1_MATH_H
