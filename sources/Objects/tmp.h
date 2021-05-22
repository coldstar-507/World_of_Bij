//
// Created by scott on 4/1/2021.
//

#ifndef WOB1_MOVINGOBJECT_H
#define WOB1_MOVINGOBJECT_H

#include "SolideObject.h"
#include <vector>

class MovingObject : public SolideObject
{
public:
    MovingObject(Vector2 p_position, std::string p_textureID, float p_acc, int p_speedLevels);
    ~MovingObject() = default;
private:
    std::vector<float> m_upSpeed, m_downSpeed, m_strafeLeftSpeed, m_strafeRightSpeed;
    std::vector<float>::const_iterator m_up, m_down, m_sl, m_sr;
    std::vector<float>::const_iterator m_upFst, m_upLst, m_downFst, m_downLst, m_slFst, m_slLst, m_srFst, m_srLst;
    std::vector<float>::const_iterator m_upSlw, m_downSlw, m_slSlw, m_srSlw;
    bool m_movingUp, m_movingDown, m_strafingLeft, m_strafingRight, m_slow;
    Vector2 m_vitesse;
public:
    Vector2 GetVitesse() const { return m_vitesse; }
public:
    void MovementRoutine(const std::vector<SolideObject*> & p_sov);
    void CalculateVitesse();
    void ApplyVitesse();
    void CheckCollisions(const std::vector<SolideObject*> & p_sov);
    void CalculateCollision(const SolideObject* p_solideObject);
    void UpMove();
    inline void MovingUp() { m_movingUp = true; }
    inline void NotMovingUp() { m_movingUp = false; }
    void DownMove();
    inline void MovingDown() { m_movingDown = true; }
    inline void NotMovingDown() { m_movingDown = false; }
    void LeftStrafe();
    inline void StrafingLeft() { m_strafingLeft = true; }
    inline void NotStrafingLeft() { m_strafingLeft = false; }
    void RightStrafe();
    inline void StrafingRight() { m_strafingRight = true; }
    inline void NotStrafingRight() { m_strafingRight = false; }
    inline void SlowlyMoving() { m_slow = true; }
    inline void NotSlowlyMoving() { m_slow = false; }
    void TurnLeft();
    void TurnRight();
    void UpdateTexturePosition();
    void UpdateHitBoxPosition();

};


#endif //WOB1_MOVINGOBJECT_H
