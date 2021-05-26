#ifndef WOB_ZONETOPOLOGIE_H
#define WOB_ZONETOPOLOGIE_H

#include <tuple>
#include <map>



struct WeightStreak
{
    int weight, streak;
};

enum class FundamentalZoneTypes
{
    Base,       // la base
    Tranquil,   //
    Medium,     //
    Wild,       // zone de poping, high monster density
    Boss        //
};

std::map<std::pair<int,int>, FundamentalZoneTypes> fundamental_map =
{
    { {0 ,  33} , FundamentalZoneTypes::Tranquil },
    { {34 , 76} , FundamentalZoneTypes::Medium   },
    { {77 , 90} , FundamentalZoneTypes::Wild     },
    { {91 , 93} , FundamentalZoneTypes::Boss     }
};

enum class Biome
{
    tundra,
    jungle,
    desert,
    swamp,
    snowfield,
    boreal,
    plainfield,
    ocean,
    mountains,
    valleyfield
};

// (pointe de tarte, biome) tarte currently has 93 units
std::map<std::pair<int,int>, Biome> biomes_map =
{
    { {0  , 14} , Biome::tundra        }, //15
    { {15 , 20} , Biome::jungle        }, //6
    { {21 , 25} , Biome::desert        }, //5
    { {26 , 32} , Biome::swamp         }, //7
    { {33 , 43} , Biome::snowfield     }, //11
    { {44 , 63} , Biome::boreal        }, //20
    { {64 , 80} , Biome::plainfield    }, //17
    { {81 , 83} , Biome::ocean         }, //3
    { {84 , 87} , Biome::mountains     }, //4
    { {88 , 93} , Biome::valleyfield   }, //6

};

enum class Place
{
    basic,
    underground,
    village,
    temple,
    plaine,
    oasis,
    cimetiere,
};

//
// (point de tarte, place) plus rare qu'un biome, donc on fait un sous-range et on return nullptr si on pogne rien
// parce ce qu'on est pas toujours dans une places, mais on est toujours dans un biome
std::map<std::pair<int,int>, Place> places_map =
{
    { {0  ,  2} , Place::underground },
    { {3  ,  4} , Place::village     },
    { {5  ,  5} , Place::temple      },
    { {6  ,  8} , Place::plaine      },
    { {9  ,  9} , Place::oasis       },
    { {10 , 10} , Place::cimetiere   },
};

std::tuple<FundamentalZoneTypes, std::pair<Biome,int>, Place> nextZones(std::pair<Biome, int> p_biome)
{
    p_biome.second--; // decrement biome streak
    int r = rand() % 94;
    int condBiomeStreak = 0;
    Biome biome;
    Place place;
    FundamentalZoneTypes fzt;
    if (!condBiomeStreak)
    {
        condBiomeStreak = rand() % 3 + 2;
        for (auto & e : biomes_map)
        {
            if (e.first.first <= r && e.first.second >= r)
                biome = e.second;
        }
    }
    for (auto & p : places_map)
    {
        if (p.first.first <= r && p.first.second >= r)
            place = p.second;
    }
    for (auto & f : fundamental_map)
    {
        if (f.first.first <= r && f.first.second >= r)
            fzt = f.second;
    }

    if (!condBiomeStreak)
    {
        return { fzt, { biome, condBiomeStreak }, place };
    }

    return { fzt, p_biome, place };

}

enum class Side
{
    right,
    down,
    left,
    up
};


Zone* GenerateZone(std::tuple<FundamentalZoneTypes, Biome, Place> tup, Side side)
{
    Zone* zone = new Zone();

    // Fundamental type switch
    switch (std::get<0>(tup))
    {
    case FundamentalZoneTypes::Tranquil:
        zone->m_monstersVector.reserve((rand() % 4) + 4);
        break;
    case FundamentalZoneTypes::Medium:
        zone->m_monstersVector.reserve(rand() % 8) + 8;
        break;
    case FundamentalZoneTypes::Wild:
        zone->m_monstersVector.reserve(rand() % 16) + 16;
        break;
    case FundamentalZoneTypes::Boss:
        zone->m_monstersVector.reserve(rand() % 2) + 2;
        break;
    default:
        break;
    }

    // Biome switch
    switch (std::get<1>(tup))
    {
    case Biome::boreal:
        zone->
        break;
    case Biome::desert:

        break;
    case Biome::jungle:

        break;
    case Biome::mountains:

        break;
    case Biome::ocean:

        break;
    case Biome::plainfield:

        break;
    case Biome::snowfield:

        break;
    case Biome::swamp:

        break;
    case Biome::tundra:

        break;
    case Biome::valleyfield:

        break;
    }

    switch(std::get<2>(tup))
    {
    case Place::basic:

        break;
    case Place::cimetiere:

        break;
    case Place::oasis:

        break;
    case Place::plaine:

        break;

    case Place::underground:

        break;
    case Place::temple:

        break;
    case Place::village:

        break;
    }



}



/*
std::tuple<float,float,float, std::pair<int,int>, Zone*> probSeed;
probSeed origine = { 1.f, 1.f, 1.f };
origine
*/

struct ZoneTopologie
{
    short difficultyLevel;
    const short maxMonstersDegree;
    FundamentalZoneTypes fundamentalZoneType;
    Biome biome;
    Place place;
    Side side;

};


#endif // WOB_ZONETOPOLOGIE_H
