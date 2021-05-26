#ifndef WOB_MONSTERS_H
#define WOB_MONSTERS_H

#include "Objects/MovingObj.h"

enum class MonsterTypes
{
    Geant,
    Gypsy,
    Goblin,
    Indigene,
    Elf,
    Pirate,
    Nymph,
    Sorcerer,
    Dwarf,
    Thug,
    Cultist,
    Forsaken,
    Charlatan,
    Kamikaze
};


class Monsters : public MovingObj
{
public:
    Monsters(Vector2 p_position, std::string p_textureID, float p_angle, float p_diametre, float p_acc, int p_speedLevels);
    ~Monsters() = default;
private:
    MonsterTypes m_monsterType;

};

#endif // WOB_MONSTERS_H
