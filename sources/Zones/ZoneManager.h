#ifndef ZONEMANAGER_H
#define ZONEMANAGER_H

#include <unordered_map>
#include "Zone.h"
#include "Objects/Player.h"
/* On va keep track des zones en les hachant sur une table de hashage
 * La cler est une paire de int qui represente le numerotage de la zone (n,m) */


struct MyHash
{
    int operator () (const std::pair<int,int> & p) const
    {
        int h1 = std::hash<float>{}(p.first);
        int h2 = std::hash<int>{}(p.second);

        return (h2 - h1) + (h1 / 2);
    }
};


class ZoneManager
{
public:
    static void Init(Player* p);
    static void Clean();
private:
    ZoneManager() = default;
    static std::unordered_map<std::pair<int,int>, Zone*, MyHash> m_zoneManager;
    static std::pair<int,int> m_zoneNum, m_lastZoneNum;
    static Zone* m_currentZone;
    static Zone* GenerateZone(std::pair<int,int>);
public:
    static Zone* CurrentZone() { return m_currentZone; }
public:
    static void ChangeZoneUp(Player* p);
    static void ChangeZoneDown(Player* p);
    static void ChangeZoneLeft(Player* p);
    static void ChangeZoneRight(Player* p);
};

#endif // ZONEMANAGER_H
