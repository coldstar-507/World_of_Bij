cmake_minimum_required(VERSION 3.10)

project(World_Of_Bij)

include_directories(sources)

if(MSVC) # Microsoft visual studio

	include_directories(
            merchants/windows/SDL2-2.0.14/include
            merchants/windows/SDL2_image-2.0.5/include
            merchants/windows/SDL2_ttf-2.0.15/include
            )
	
        link_directories( # Interchanger ces libs si on veut build soit x64 ou x86
            merchants/windows/SDL2-2.0.14/lib/x64
            merchants/windows/SDL2_image-2.0.5/lib/x64
            merchants/windows/SDL2_ttf-2.0.15/lib/x64

            merchants/windows/SDL2-2.0.14/lib/x86
            merchants/windows/SDL2_image-2.0.5/lib/x86
            merchants/windows/SDL2_ttf-2.0.15/lib/x86
        )


elseif(UNIX) # Pour linux build avec les libs installer system level
    set(CMAKE_CXX_STANDARD 17)
    include(FindPkgConfig)

    pkg_search_module(SDL2 REQUIRED sdl2)
    pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
    pkg_search_module(SDL2TTF REQUIRED SDL2_ttf)

    include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2GFX_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})

elseif(WIN32)
    include_directories(
            vendors/SDL/mingw/SDL2-2.0.14/x86_64-w64-mingw32/include/SDL2
            vendors/SDL/mingw/SDL2_image-2.0.5/x86_64-w64-mingw32/include/SDL2
            vendors/SDL/mingw/SDL2_ttf-2.0.15/x86_64-w64-mingw32/include/SDL2
            C:/boost/include/boost-1_75
    )

    link_directories(
            vendors/SDL/mingw/SDL2-2.0.14/x86_64-w64-mingw32/lib
            vendors/SDL/mingw/SDL2_image-2.0.5/x86_64-w64-mingw32/lib
            vendors/SDL/mingw/SDL2_ttf-2.0.15/x86_64-w64-mingw32/lib
            C:/boost/lib
    )
endif()

add_executable(WoB WoB.cpp
        sources/Core/Engine.cpp
        sources/Objects/Entity.cpp
        sources/Objects/Player.cpp
        sources/Objects/RectangleObj.cpp
        sources/Objects/LosangeObj.cpp
        sources/Objects/OctogoneObj.cpp
        sources/Objects/MovingObj.cpp
        sources/Objects/StarObj.cpp
        sources/GameObject/Monsters.cpp
        sources/Core/Camera.cpp
        sources/Core/Drawer.cpp
        sources/2DPhysics/Math.cpp
        sources/Texture/TextureBank.cpp
        sources/Texture/Texture.cpp
        sources/Zones/Zone.cpp
        sources/Zones/ZoneManager.cpp
        )

target_link_libraries(WoB SDL2 SDL2main SDL2_image SDL2_ttf
        #boost_atomic-mgw8-mt-d-x64-1_75
        #boost_filesystem-mgw8-mt-d-x64-1_75
        )

add_executable(Sandbox sandbox/Run.cpp
        sandbox/SandboxApp.cpp
        sources/Core/Engine.cpp
        sources/Objects/Player.cpp
        sources/Objects/Entity.cpp
        sources/Objects/RectangleObj.cpp
        sources/Objects/LosangeObj.cpp
        sources/Objects/StarObj.cpp
        sources/Objects/OctogoneObj.cpp
        sources/Objects/MovingObj.cpp
        sources/Core/Camera.cpp
        sources/Core/Drawer.cpp
        sources/GameObject/Monsters.cpp
        sources/2DPhysics/Math.cpp
        sources/Texture/TextureBank.cpp
        sources/Texture/Texture.cpp
        sources/Zones/Zone.cpp
        sources/Zones/ZoneManager.cpp
        )

target_link_libraries(Sandbox SDL2 SDL2main SDL2_image SDL2_ttf
        #boost_atomic-mgw8-mt-d-x64-1_75
        #boost_filesystem-mgw8-mt-d-x64-1_75
        )
