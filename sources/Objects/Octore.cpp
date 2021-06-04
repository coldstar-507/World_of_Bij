#include "Octore.h"
#include <cmath>

float coslaw(float a, float b, float c)
{
    return std::acos((a*a + b*b - c*c) / 2.f * a * b);
}



Octore::Octore()
{
    m_points.reserve(8);

    Vector2 p1,p2,p3,p4,p5,p6,p7,p8;
    std::vector<Vector2> tmpv(8);

    m_center = MiddlePoint(MiddlePoint(MiddlePoint(p1, p5), MiddlePoint(p3, p7)), MiddlePoint(MiddlePoint(p2, p6), MiddlePoint(p4, p8)));

    Vector2 importantPoint;

    if (m_center.y > p7.y && m_center.y <= p8.y)
        importantPoint = { m_center.y - _B(p7, p8), m_center.y };
    else if (m_center.y > p8.y && m_center.y <= p1.y)
        importantPoint = { p8.x, m_center.y };
    else if (m_center.y > p1.y && m_center.y <= p2.y)
        importantPoint = { _B(p1, p2) - m_center.y, m_center.y };

    float alpha, a, b, c;
    a = Distance(m_center, importantPoint);
    b = Distance(m_center, p1);
    c = Distance(importantPoint, p1);
    alpha = coslaw(a,b,c);

    bool singles[8];
    bool doubles[8];
    bool triples[8];
    for (int i = 0; i < 8; i++)
    {
        if (tmpv[i] == tmpv[(i + 1) % 8]) {
            doubles[i] = true;
            doubles[(i + 1) % 8] = true;
        }
        else if (!doubles[i])
            singles[i] = true;
    }
    for (int i = 0; i < 8; i++)
    {
        if (doubles[i] && doubles[(i + 1) % 8]) {
            triples[i] = true;
            doubles[i] = false;
            doubles[(i + 1) % 8] = false;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (triples[i]) {
            m_corners.push_back(i + 16);

        }
        else if (doubles[i])
            m_corners.push_back(i + 8);
        else if (singles[i])
            m_corners.push_back(i);
    }

}
