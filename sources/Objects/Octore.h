#ifndef OCTORE_H
#define OCTORE_H

#include "2DPhysics/Math.h"
#include <vector>



enum Corners // an 8 side octore would have the first row signature, eg all 8 corners.
                                 // You can't have One and OneTwo simultaneously
{
    _0,_1,_2,_3,_4,_5,_6,_7,
    _01,_12,_23,_34,_45,_56,_67,_70,
    _012,_123,_234,_345,_456,_567,_670,_701
};

enum class Lines
{
    x,y,xy,_xy
}; // There are 24 corners type but only 4 possible lines and 8 collision types (Lines and inverse of lines)

enum class CollisionTypes
{
    x,y,
    _x,_y,
    xy,_xy,
    _x_y,x_y
};

float _B(const Vector2 &p1, const Vector2 &p2)
{
    float a,b;
    a = p2.y - p1.y / p2.x - p1.x;
    b = p1.y - a * p1.x;
    return b;
}

struct OctorePoint
{
    Vector2 position;
    float angle, angle_; // angle_ is angle - alpha
    std::pair<OctorePoint, OctorePoint>* hole = nullptr;
    Corners corner;
    Lines line;
};



class Octore
{
public:
    Octore();
private:
    Vector2 m_center;
    std::vector<OctorePoint> m_points;
    std::vector<Corners> m_corners; // Un octore est max 8 corners et min 3 corners
};

#endif // OCTORE_H
