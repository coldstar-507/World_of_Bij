#ifndef WOB_MOVINGOBJ_H
#define WOB_MOVINGOBJ_H

#include <vector>
#include "OctogoneObj.h"
#include "RectangleObj.h"
#include "LosangeObj.h"
#include "StarObj.h"

class MovingObj : public StarObj
{
public:
    MovingObj(Vector2 p_position, std::string p_textureID, float p_angle, float p_diametre, float p_acc, int p_speedLevels);
    ~MovingObj() = default;
private:
    std::vector<float> m_upSpeed, m_downSpeed, m_strafeLeftSpeed, m_strafeRightSpeed;
    std::vector<float>::const_iterator m_up, m_down, m_sl, m_sr;
    std::vector<float>::const_iterator m_upFst, m_upLst, m_downFst, m_downLst, m_slFst, m_slLst, m_srFst, m_srLst;
    std::vector<float>::const_iterator m_upSlw, m_downSlw, m_slSlw, m_srSlw;
    bool m_movingUp, m_movingDown, m_strafingLeft, m_strafingRight, m_slow;
public:
    void UpdatePositions();
    void MovementRoutine(const std::vector<OctogoneObj*> & p_oov, const std::vector<RectangleObj*> & p_rov,
                         const std::vector<LosangeObj*> & p_lov, const std::vector<MovingObj*> & p_mov);
    void CalculateVitesse();
    void ApplyVitesse();
    void CheckCollisions(const std::vector<OctogoneObj*> & p_oov, const std::vector<RectangleObj*> & p_rov,
                         const std::vector<LosangeObj*> & p_lov, const std::vector<MovingObj*> & p_mov);
    void UpMove();
    void DownMove();
    void LeftStrafe();
    void RightStrafe();
    void TurnLeft();
    void TurnRight();
public:
    inline void MovingUp() { m_movingUp = true; }
    inline void NotMovingUp() { m_movingUp = false; }
    inline void MovingDown() { m_movingDown = true; }
    inline void NotMovingDown() { m_movingDown = false; }
    inline void StrafingLeft() { m_strafingLeft = true; }
    inline void NotStrafingLeft() { m_strafingLeft = false; }
    inline void StrafingRight() { m_strafingRight = true; }
    inline void NotStrafingRight() { m_strafingRight = false; }
    inline void SlowlyMoving() { m_slow = true; }
    inline void NotSlowlyMoving() { m_slow = false; }
};

#endif // WOB_MOVINGOBJ_H
