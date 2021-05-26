//
// Created by scott on 4/1/2021.
//

#ifndef WOB_TEXTURE_H
#define WOB_TEXTURE_H

#include <string>
#include "SDL_image.h"
#include "2DPhysics/Math.h"


class Texture
{
public:
    explicit Texture(const std::string& p_texturePath);
    void LoadTextureFromFile(const std::string& p_texturePath);
    void Clean();
    int GetWidth() const { return m_width; }
    int GetHeight() const { return m_height; }
    Vector2 GetCenter() const { return m_center; }
    SDL_Texture* GetTexture() { return m_texture; }

private:
    SDL_Texture* m_texture;
    int m_width, m_height;
    Vector2 m_center;
};


#endif //WOB_TEXTURE_H
