#include "Entity.h"
#include "Texture/TextureBank.h"
#include "Core/Draw.h"


Entity::Entity(Vector2 p_position, std::string p_textureID, float p_angle)
    : m_uniqueID(rand()), m_position(p_position), m_textureID(p_textureID), m_angle(p_angle), m_targeted(false)
{
    m_texturePosition = m_position - TextureBank::GetTexture(m_textureID)->GetCenter();
}

void Entity::UpdateTexturePosition()
{
    m_texturePosition = m_position - TextureBank::GetTexture(m_textureID)->GetCenter();
}

void Entity::DrawRayon()
{
    DrawCircle(m_position, m_rayon);
}

void Entity::DrawBigRayon()
{
    DrawCircle(m_position, m_bigRayon);
}

void Entity::DrawTexture()
{
    Draw(m_textureID, m_texturePosition, RadToDeg(m_angle));
}
