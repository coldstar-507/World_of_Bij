#ifndef STAROBJ_H
#define STAROBJ_H

#include <vector>
#include "OctogoneObj.h"
#include "LosangeObj.h"
#include "RectangleObj.h"

// Le predececeur du moving object, all moving objects are star objects and vice-versa
// On lui donne vitesse et fonction de collision pour alleger la classe moving objects

class StarObj : public Entity
{
public:
    StarObj(Vector2 p_position, std::string p_textureID, float p_angle, float p_diametre);
    ~StarObj() = default;
protected:
    float m_diametre;
    Quad m_rect, m_losa;
    CriticalAngles m_rectCrit, m_losaCrit;
    OctCriticalAngles m_octCrit;
    Octogone m_oct;
    Vector2 m_vitesse;
public:
    void DrawStar();
    void UpdateStarPositions();
    CriticalAngles GetRectCrit() const { return m_rectCrit; }
    CriticalAngles GetLosaCrit() const { return m_losaCrit; }
    OctCriticalAngles GetOctCrit() const { return m_octCrit; }
    Octogone GetOctogone() const { return m_oct; }
    Quad GetRect() const { return m_rect; }
    Quad GetLosa() const { return m_losa; }
    Vector2 GetVitesse() const { return m_vitesse; }
public:
    void StarCollision(const StarObj* sob);
    void OctogoneCollision(const OctogoneObj* oob);
    void RectangleCollision(const RectangleObj* rob);
    void LosangeCollision(const LosangeObj* lob);


};

#endif // STAROBJ_H
