cmake_minimum_required(VERSION 3.10)

project(World_of_Bij)

include_directories(sources)

if(MSVC) # Microsoft visual studio
    include_directories(
        merchants/windows/msvc/SDL2-2.0.14/include
        merchants/windows/msvc/SDL2_image-2.0.5/include
        merchants/windows/msvc/SDL2_ttf-2.0.15/include
        merchants/windows/msvc/boost-1_76/include
        )

    link_directories(
        merchants/windows/msvc/SDL2-2.0.14/lib/x64
        merchants/windows/msvc/SDL2_image-2.0.5/lib/x64
        merchants/windows/msvc/SDL2_ttf-2.0.15/lib/x64
        merchants/windows/msvc/boost-1_76/lib/atomic/build/msvc-14.2/debug/threading-multi
        merchants/windows/msvc/boost-1_76/lib/atomic/build/msvc-14.2/debug/link-static/threading-multi
        merchants/windows/msvc/boost-1_76/lib/filesystem/build/msvc-14.2/debug/threading-multi
        merchants/windows/msvc/boost-1_76/lib/filesystem/build/msvc-14.2/debug/link-static/threading-multi
        )


elseif(UNIX) # Pour linux build avec les libs installer system level
    set(CMAKE_CXX_STANDARD 17)
    include(FindPkgConfig)

    pkg_search_module(SDL2 REQUIRED sdl2)
    pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
    pkg_search_module(SDL2TTF REQUIRED SDL2_ttf)

    include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2GFX_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})

elseif(MINGW)
    include_directories(
        merchants/windows/mingw/SDL2-2.0.14/x86_64-w64-mingw32/include
        merchants/windows/mingw/SDL2_image-2.0.5/x86_64-w64-mingw32/include
        merchants/windows/mingw/SDL2_ttf-2.0.15/x86_64-w64-mingw32/include
        merchants/windows/mingw/boost-1_75/include
        )

    link_directories(
        merchants/windows/mingw/SDL2-2.0.14/x86_64-w64-mingw32/lib
        merchants/windows/mingw/SDL2_image-2.0.5/x86_64-w64-mingw32/lib
        merchants/windows/mingw/SDL2_ttf-2.0.15/x86_64-w64-mingw32/lib
        merchants/windows/mingw/boost-1_75/lib
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
    sources/Core/Draw.cpp
    sources/2DPhysics/Math.cpp
    sources/Texture/TextureBank.cpp
    sources/Texture/Texture.cpp
    sources/Zones/Zone.cpp
    sources/Zones/ZoneManager.cpp
    )
if(MSVC)
    target_link_libraries(WoB SDL2 SDL2main SDL2_image SDL2_ttf
        boost_atomic-vc142-mt-gd-x64-1_76
        boost_filesystem-vc142-mt-gd-x64-1_76
        )
elseif(MINGW)
    target_link_libraries(WoB SDL2 SDL2main SDL2_image SDL2_ttf
        boost_atomic-mgw8-mt-d-x64-1_75
        boost_filesystem-mgw8-mt-d-x64-1_75
        )
elseif(UNIX)
    target_link_libraries(WoB SDL2 SDL2main SDL2_image SDL2_ttf
        )
endif()

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
    sources/Core/Draw.cpp
    sources/GameObject/Monsters.cpp
    sources/2DPhysics/Math.cpp
    sources/Texture/TextureBank.cpp
    sources/Texture/Texture.cpp
    sources/Zones/Zone.cpp
    sources/Zones/ZoneManager.cpp
    )

if(MSVC)
    target_link_libraries(Sandbox SDL2 SDL2main SDL2_image SDL2_ttf
        boost_atomic-vc142-mt-gd-x64-1_76
        boost_filesystem-vc142-mt-gd-x64-1_76
        )
elseif(MINGW)
    target_link_libraries(Sandbox SDL2 SDL2main SDL2_image SDL2_ttf
        boost_atomic-mgw8-mt-d-x64-1_75
        boost_filesystem-mgw8-mt-d-x64-1_75
        )
elseif(UNIX)
    target_link_libraries(Sandbox SDL2 SDL2main SDL2_image SDL2_ttf
        )
endif()
