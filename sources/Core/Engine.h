//
// Created by scott on 4/1/2021.
//

#ifndef WOB1_ENGINE_H
#define WOB1_ENGINE_H

#include "SDL.h"
#include "meta.h"

class Engine
{
public:
    static void Init();
    static void Events(SDL_Event* p_event);
    static void Loop();
    static void Render();
    static void Stop();
    static void Quit();

    static SDL_Renderer* GetRenderer() { return m_renderer; }
    static SDL_Window* GetWindow() { return m_window; }
    static bool IsRunning() { return m_running; }

private:
    Engine() = default;
    static bool m_running;
    static SDL_Renderer* m_renderer;
    static SDL_Window* m_window;

};


#endif //WOB1_ENGINE_H
