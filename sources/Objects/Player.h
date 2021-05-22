#ifndef PLAYER_H
#define PLAYER_H

#include "MovingObj.h"
#include "GameObject/Monsters.h"

class Player : public MovingObj
{
public:
    Player(Vector2 p_position, std::string p_textureID, float p_angle, float p_diametre, float p_acc, int p_speedLevels);
    ~Player() = default;
private:
    std::vector<Monsters*> m_monsterTargetBuffer;
    struct TargetDots {
        Vector2 position;
        float rayon,distance;
    } m_targetDots[3];

    Vector2 m_mousePosition;
    int m_mouseX, m_mouseY; // Need this because that's how SDL works
public:
    Monsters* m_monsterTarget = nullptr;

    std::pair<int*,int*> GetMouseXYAdress() { return { &m_mouseX, &m_mouseY }; }
    Vector2 GetMousePosition() const { return m_mousePosition; }
public:
    void ApplyVitesse();
    inline void ResetMonsterTarget() { m_monsterTarget = nullptr; }
    void TargetMonsters(const std::vector<Monsters*> & p_mv);
    void MovementRoutine(const std::vector<OctogoneObj*> & p_oov, const std::vector<RectangleObj*> & p_rov,
                         const std::vector<LosangeObj*> & p_lov, const std::vector<MovingObj*> & p_mov);
    void UpdateTargetDotsPositions();
    void CalculateMousePosition();
    void CalculateAngleFromMouse(); // We would want to be able to choose mouse gameplay vs arrow gameplay
    void DrawTargetCircles();
    void DrawMonsterTarget();
};

#endif // PLAYER_H
