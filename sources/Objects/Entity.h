#ifndef ENTITY_H
#define ENTITY_H

#include <cstdlib>
#include <cstdio>
#include <string>

#include "2DPhysics/Math.h"

class Entity
{
public:
    Entity(Vector2 p_position, std::string p_textureID = "empty", float p_angle = 0.f);
    ~Entity() = default;
private:
    int m_uniqueID;
    std::string m_textureID;
protected:
    float m_angle, m_rayon, m_bigRayon;
    Vector2 m_position, m_texturePosition;
public:
    bool m_targeted;
public:
    int GetUniqueID() const { return m_uniqueID; }
    float GetRayon() const { return m_rayon; }
    float GetBigRayon() const { return m_bigRayon; }
    float GetAngle() const { return m_angle; }
    Vector2 GetPosition() const { return m_position; }
    Vector2* GetPositionAdress() { return &m_position; }
    Vector2 GetTexturePosition() const { return m_texturePosition; }
    Vector2* GetTexturePositionAdress() { return &m_texturePosition; }
    std::string GetTextureID() const { return m_textureID; }
public:
    void UpdateTexturePosition();
    void DrawRayon();
    void DrawBigRayon();
    void DrawTexture();
};

#endif // ENTITY_H
