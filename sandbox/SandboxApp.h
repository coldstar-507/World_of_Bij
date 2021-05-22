//
// Created by scott on 4/5/2021.
//

#ifndef WOB1_SANDBOXAPP_H
#define WOB1_SANDBOXAPP_H

#include "Core/Engine.h"
#include "Texture/TextureBank.h"
#include "Core/Timer.h"
#include "Core/Camera.h"
#include "Core/Drawer.h"
#include "2DPhysics/Math.h"
#include "Zones/ZoneManager.h"
#include "Objects/Player.h"

#include "SDL.h"
#include "SDL_image.h"

class SandboxApp : public Engine
{
public:
    static void Init();
    static void Render();
    static void Loop();
    static void Events(SDL_Event* event);
    static void Quit();
private:
    static Player* player;

};




#endif //WOB1_SANDBOXAPP_H
