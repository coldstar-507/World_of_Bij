//
// Created by scott on 4/5/2021.
//

#include "SandboxApp.h"
#include "Scratch.h"
#include <cstring>

Player* SandboxApp::player = nullptr;

void SandboxApp::Init()
{
    srand(time(NULL));
    SandboxApp::Engine::Init();
    TextureBank::Init();
    Vector2 pf = { 1000.f, 1000.f };
    player = new Player( pf, "gris", 0.f, 90.f, .12f, 30);
    ZoneManager::Init(player);
    Camera::Init(player->GetPositionAdress());

}

void SandboxApp::Render()
{
    SDL_RenderClear(SandboxApp::GetRenderer());


    ZoneManager::CurrentZone()->DrawGrid();
    //ZoneManager::CurrentZone()->DrawBigRayons();
    ZoneManager::CurrentZone()->DrawLosanges();
    ZoneManager::CurrentZone()->DrawOcts();
    //ZoneManager::CurrentZone()->DrawRayons();
    ZoneManager::CurrentZone()->DrawTextures();
    ZoneManager::CurrentZone()->DrawRects();
    ZoneManager::CurrentZone()->DrawStars();

    Draw("alexcropped", { 450.f, 450.f });

    player->DrawTargetCircles();
    //player->DrawMonsterTarget();


    SDL_RenderPresent(SandboxApp::GetRenderer());
}

void SandboxApp::Loop()
{
    //player->MovementRoutine();
    ZoneManager::CurrentZone()->MovingObjectsMovementRoutine();
    Camera::Update();
    ZoneManager::ChangeZoneUp(player);
    ZoneManager::ChangeZoneDown(player);
    ZoneManager::ChangeZoneLeft(player);
    ZoneManager::ChangeZoneRight(player);
}

void SandboxApp::Events(SDL_Event *event)
{
    if (event->key.repeat == 0)
    {
        switch (event->type)
        {
        case SDL_MOUSEWHEEL:
        {
            if (event->wheel.y > 0) // scroll up
            {
                Camera::Zoom(1.05f);
            }
            else if (event->wheel.y < 0) // scroll down
            {
                Camera::Zoom(0.95f);
            }
        }
        case SDL_KEYDOWN:
        {
            switch (event->key.keysym.sym)
            {
            case SDLK_LSHIFT:
            {
                player->SlowlyMoving();
                break;
            }
            case SDLK_TAB:
            {
                //player->TargetMonsters(ZoneManager::CurrentZone()->m_monstersVector);
                Loger::log(player->m_monsterTarget);
                break;
            }
            case SDLK_ESCAPE:
            {
                SandboxApp::Stop();
                break;
            }
            case SDLK_RIGHT:
            {
                player->StrafingRight();
                break;
            }
            case SDLK_LEFT:
            {
                player->StrafingLeft();
                break;
            }
            case SDLK_UP:
            {
                player->MovingUp();
                break;
            }
            case SDLK_DOWN:
            {
                player->MovingDown();
                break;
            }
            }
            break;
        }
        case SDL_KEYUP:
        {
            switch (event->key.keysym.sym)
            {
            case SDLK_LSHIFT:
            {
                player->NotSlowlyMoving();
                break;
            }
            case SDLK_RIGHT:
            {
                player->NotStrafingRight();
                break;
            }
            case SDLK_LEFT:
            {
                player->NotStrafingLeft();
                break;
            }
            case SDLK_UP:
            {
                player->NotMovingUp();
                break;
            }
            case SDLK_DOWN:
            {
                player->NotMovingDown();
                break;
            }
            }
        }
        case SDL_MOUSEBUTTONDOWN:
        {
            break;
        }
        case SDL_MOUSEMOTION:
        {
            SDL_GetMouseState(player->GetMouseXYAdress().first, player->GetMouseXYAdress().second);
            break;
        }
        case SDL_QUIT:
        {
            SandboxApp::Stop();
            break;
        }
        }
    }
}

void SandboxApp::Quit()
{
    delete(player);
    SandboxApp::Engine::Quit();
}
