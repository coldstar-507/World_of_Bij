//
// Created by scott on 4/1/2021.
//


#include "Engine.h"
#include "meta.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL.h"
#include "Texture/TextureBank.h"
#include "Camera.h"

SDL_Renderer* Engine::m_renderer = nullptr;
SDL_Window* Engine::m_window = nullptr;
bool Engine::m_running = false;

void Engine::Init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        SDL_Log("Failed to init everything : %s", SDL_GetError());
    }

    if ((m_window = SDL_CreateWindow("World of Bij",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        WINDOW_SIZE_X, WINDOW_SIZE_Y,
                                        SDL_WINDOW_OPENGL)) == nullptr)
    {
        SDL_Log("Failed to create window : %s", SDL_GetError());
    }

    if ((m_renderer = SDL_CreateRenderer(m_window, -1, 0)) == nullptr)
    {
        SDL_Log("Failed to create renderer : %s", SDL_GetError());
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        SDL_Log("Failed to init IMG_PNG : %s", SDL_GetError());
    }
    /*
    if (!(TTF_Init()))
    {
        SDL_Log("Failed to init TTF : %s", SDL_GetError());
    }
     */

    m_running = true;
}

void Engine::Render()
{

}

void Engine::Loop()
{

}

void Engine::Events(SDL_Event *p_event)
{
    switch (p_event->type)
    {
        case SDL_KEYDOWN:
        {
            switch (p_event->key.keysym.sym)
            {
                case SDLK_TAB:
                {
                    break;
                }
                case SDLK_ESCAPE:
                {
                    m_running = false;
                    break;
                }
                case SDLK_RIGHT:
                {
                    break;
                }
                case SDLK_LEFT:
                {
                    break;
                }
                case SDLK_UP:
                {
                    break;
                }
                case SDLK_DOWN:
                {
                    break;
                }
            }
            break;
        }
        case SDL_MOUSEMOTION:
        {

            break;
        }
        case SDL_QUIT:
        {
            m_running = false;
            break;
        }
    }
}

void Engine::Stop()
{
    m_running = false;
}

void Engine::Quit()
{
    TextureBank::Clean();
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    //TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
