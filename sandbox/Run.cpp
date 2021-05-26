//
// Created by scott on 4/5/2021.
//

#include "SandboxApp.h"

#if __MINGW32__

int WinMain(int argc, char* argv[])
{
    SandboxApp::Init();
    Timer t(10);

    SDL_Event event;
    while (SandboxApp::IsRunning()) // Game loop
    {
        t.Start();

        while (SDL_PollEvent(&event))
        {
            SandboxApp::Events(&event);
        }

        SandboxApp::Loop();
        SandboxApp::Render();

        t.Delay();
    }
    SandboxApp::Quit();
    return 0;
}

#else

int main(int argc, char* argv[])
{
    SandboxApp::Init();
    Timer t(10); // Environ 17 pour 60 fps // it does work now
    SDL_Event event;
    while (SandboxApp::IsRunning()) // Game loop
    {
        t.Start();
        while (SDL_PollEvent(&event))
        {
            SandboxApp::Events(&event);
        }
        SandboxApp::Loop();
        SandboxApp::Render();
        t.Delay();
    }
    SandboxApp::Quit();
    return 0;
}

#endif
