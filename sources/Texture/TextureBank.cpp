//
// Created by scott on 4/1/2021.
//

#include "TextureBank.h"
#include "Core/Engine.h"
#include "Core/Camera.h"
#include "Core/Loger.h"

#ifdef _WIN32

#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

#elif __linux__

#include <filesystem>
namespace fs = std::filesystem;

#endif

std::unordered_map<std::string, Texture*> TextureBank::m_textureBank;

void TextureBank::Init()
{
    fs::directory_iterator res_it("../../../ressources/images");
    fs::directory_iterator end_it;

    std::string tmp_filePath;
    std::string tmp_assetID;

    for (res_it; res_it != end_it; res_it++)
    {
        fs::directory_iterator tmp_it(res_it->path());
        for (tmp_it; tmp_it != end_it; tmp_it++)
        {
            tmp_assetID = tmp_it->path().stem().string();
            tmp_filePath = tmp_it->path().string();
            m_textureBank[tmp_assetID] = new Texture(tmp_filePath);
            Loger::logf("Loaded [%s] at %s", tmp_assetID.c_str(), tmp_filePath.c_str());
        }
    }

}

void TextureBank::Clean()
{
    for (auto& it : m_textureBank)
    {
        it.second->Clean();
        delete(it.second);
    }
}

void TextureBank::Draw(const std::string & p_textureID, Vector2 p_position, float p_angle, SDL_FPoint* p_center)
{
    SDL_FRect dstRect = {
            ( (p_position.x - Camera::Position().x) * Camera::CurrentZoom() ) + Camera::Center().x,
            ( (p_position.y - Camera::Position().y) * Camera::CurrentZoom() ) + Camera::Center().y,
            (float) m_textureBank[p_textureID]->GetWidth() * Camera::CurrentZoom(),
            (float) m_textureBank[p_textureID]->GetHeight() * Camera::CurrentZoom()
    };
    SDL_RenderCopyExF(
            Engine::GetRenderer(),
            m_textureBank[p_textureID]->GetTexture(),
            nullptr,
            &dstRect,
            p_angle,
            p_center,
            SDL_FLIP_NONE
            );
}

