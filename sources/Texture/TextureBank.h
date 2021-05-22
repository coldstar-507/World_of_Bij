//
// Created by scott on 4/1/2021.
//

#ifndef WOB1_TEXTUREBANK_H
#define WOB1_TEXTUREBANK_H

#include <unordered_map>
#include "Texture.h"
#include "2DPhysics/Math.h"

class TextureBank
{
public:
    static void Init();
    static void Clean();
    static void Draw(const std::string& p_textureID, Vector2 p_position, float p_angle = 0.f, SDL_FPoint* p_center = nullptr);

    static std::unordered_map<std::string, Texture*>* GetTextureBank()
    {
        return &m_textureBank;
    }
    static Texture* GetTexture(const std::string& p_textureID)
    {
        return m_textureBank[p_textureID];
    }

private:
    TextureBank() = default;
    static std::unordered_map<std::string, Texture*> m_textureBank;
};


#endif //WOB1_TEXTUREBANK_H
