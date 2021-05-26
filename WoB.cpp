#include "Core/Timer.h"
#include <SDL.h>
#include "Core/Engine.h"

#ifdef __MINGW32__

int WinMain(int argc, char* argv[])
{
    Engine::Init();
    Timer t(10);

    SDL_Event event;
    while (Engine::IsRunning())
    {
        while (SDL_PollEvent(&event))
        {
            Engine::Events(&event);
        }
        t.Start();

        Engine::Loop();
        Engine::Render();

        t.Delay();
    }

    Engine::Quit();

    return 0;
}

#else

int main(int argc, char* argv[])
{
    Engine::Init();
    Timer t(17); // makes sure the stuff between t.start() and t.delay() takes 17 ms, about 60 fps

    SDL_Event event;
    while (Engine::IsRunning())
    {
        while (SDL_PollEvent(&event))
        {
            Engine::Events(&event);
        }
        t.Start();

        Engine::Loop();
        Engine::Render();

        t.Delay();
    }

    Engine::Quit();

    return 0;
}

#endif
