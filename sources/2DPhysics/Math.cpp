//
// Created by scott on 4/1/2021.
//
#include <cmath>
#include "Math.h"
#include <cstdio>
#include "meta.h"

float Vector2::Normal()
{
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}

float RadToDeg(float p_rad)
{
    return (p_rad * 180) / M_PI;
}

float DegToRad(float p_deg)
{
    return (p_deg * M_PI) / 180;
}

float Distance(const Vector2& p1, const Vector2& p2)
{
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

Vector2 RotationTransform(const Vector2 &p, float angle)
{
    return {
        (p.x * std::cos(angle)) - (p.y * std::sin(angle)) ,
                ((p.x * std::sin(angle)) + (p.y * std::cos(angle)))

    };
}

float RelativeAngle(const Vector2& p1, const Vector2& p2)
{
    float opp = std::abs(p2.y - p1.y);
    float adj = std::abs(p2.x - p1.x);
    float angle = std::atan(opp/adj);

    if (p1.x < p2.x && p1.y > p2.y) // p1 est en bas a gauche de p2
    {
        return 2*M_PI - angle;
    }
    else if (p1.x < p2.x && p1.y <= p2.y) // p1 est en haut a gauche de p2
    {
        return angle;
    }
    else if (p1.x >= p2.x && p1.y < p2.y) // p1 est en haut a droite de p2
    {
        return M_PI - angle;
    }
    else // p1 est en bas a droite de p2
    {
        return M_PI + angle;
    }
}

Vector2 RandomPoint()
{
    return { (float) (rand() % REGION_SIZE_X), (float) (rand() % REGION_SIZE_Y) };
}

void PrintV2(const Vector2 &v, const char *msg)
{
    printf("%s position (x,y) : (%.2f,%.2f)\n", msg, v.x, v.y);
}

int Loger::i = 0;

