//
// Created by scott on 4/1/2021.
//

#include "Texture.h"
#include "Core/Engine.h"

Texture::Texture(const std::string &p_texturePath)
{
    SDL_Surface* tmpSurface;
    tmpSurface = IMG_Load(p_texturePath.c_str());
    if (!tmpSurface)
    {
        SDL_Log("Failed to load image : %s : %s", p_texturePath.c_str(), IMG_GetError());
    }

    if ((m_texture = SDL_CreateTextureFromSurface(Engine::GetRenderer(), tmpSurface)) == nullptr)
    {
        SDL_Log("Failed to create texture from surface : %s", IMG_GetError());
    }

    SDL_QueryTexture(m_texture, nullptr, nullptr, &m_width, &m_height);

    m_center = { (float) m_width / 2.f, (float) m_height / 2.f };

    SDL_FreeSurface(tmpSurface);
}

void Texture::LoadTextureFromFile(const std::string &p_texturePath)
{
    SDL_Surface* tmpSurface;
    tmpSurface = IMG_Load(p_texturePath.c_str());
    if (!tmpSurface)
    {
        SDL_Log("Failed to load image : %s : %s", p_texturePath.c_str(), IMG_GetError());
    }

    if ((m_texture = SDL_CreateTextureFromSurface(Engine::GetRenderer(), tmpSurface)) == nullptr)
    {
        SDL_Log("Failed to create texture from surface : %s", IMG_GetError());
    }

    SDL_QueryTexture(m_texture, nullptr, nullptr, &m_width, &m_height);
    SDL_FreeSurface(tmpSurface);

}

void Texture::Clean()
{
    SDL_DestroyTexture(m_texture);
}




