//
// Created by scott on 4/2/2021.
//

#ifndef WOB1_ZONE_H
#define WOB1_ZONE_H

//#include "ZoneTopologie.h"
#include "GameObject/Monsters.h"
#include "GameObject/EnvironementObject.h"
#include "Objects/Player.h"
#include "GameObject/Boss.h"
#include <vector>
#include <tuple>

enum class FundamentalZoneTypes
{
    Base,
    Wild
};

enum class Biome
{
    tmp
};

enum class Place
{
    tmp
};

class Zone
{
public:
    Zone(int nbRects, int nbLosanges, int nbOcts, int nbMovs, Player*);
    ~Zone();

    int ZoneID;
    // Base Vectors
    std::vector<Entity*> m_entityVector;
    std::vector<RectangleObj*> m_rectObjectVector;
    std::vector<LosangeObj*> m_losangeObjectVector;
    std::vector<OctogoneObj*> m_octObjectVector;
    std::vector<MovingObj*> m_movingObjectVector;
    // Specific Vectors
    //std::vector<EnvironementObject*> m_envObjectVector;
    //std::vector<Monsters*> m_monstersVector;
    //std::vector<Player*> m_playersVector;
    //Boss* m_boss;

    // ZoneTopologie m_topologie;
    FundamentalZoneTypes m_zoneType;

    std::tuple<FundamentalZoneTypes, std::pair<Biome, int>, Place> m_zoneGenParam;

    void MovingObjectsMovementRoutine();

    void DrawGrid();
    void DrawTextures();
    void DrawRects();
    void DrawLosanges();
    void DrawRayons();
    void DrawBigRayons();
    void DrawOcts();
    void DrawStars();
};


#endif //WOB1_ZONE_H
