#ifndef WOB_OCTAGONALOBJECT_H
#define WOB_OCTAGONALOBJECT_H

#include "Entity.h"
#include <string>
#include <cmath>
#include "2DPhysics/Math.h"

class OctogoneObj : public Entity
{
public:
    OctogoneObj(Vector2 p_position, std::string p_textureID, float p_angle, float p_diametre);
    ~OctogoneObj() = default;
private: // These don't change once initialized
    float m_diametre;
protected: // These are all subject to change in child classes
    OctCriticalAngles m_octCrit;
    Octogone m_oct;
public:
    Octogone GetOctogone() const { return m_oct; }
    OctCriticalAngles GetOctCrit() const { return m_octCrit; }
public:
    void DrawOct();
    void OctogonalCollision(OctogoneObj* oob);
    void UpdateOctPosition();
};



#endif // WOB_OCTAGONALOBJECT_H
