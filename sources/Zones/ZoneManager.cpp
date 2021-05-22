#include "ZoneManager.h"
#include "meta.h"


std::unordered_map<std::pair<int,int>, Zone*, MyHash> ZoneManager::m_zoneManager;
std::pair<int,int> ZoneManager::m_zoneNum;
std::pair<int,int> ZoneManager::m_lastZoneNum;
Zone* ZoneManager::m_currentZone = nullptr;

void ZoneManager::Init(Player* p) // J'imagine qu'on va avoir un map ID est un pointer sur le save
{
    m_zoneNum = {0, 0};
    m_zoneManager.insert( { m_zoneNum, new Zone(3, 3, 3, 1, p) } );
    m_currentZone = m_zoneManager.at(m_zoneNum);
}

void ZoneManager::Clean()
{
    // Save and delete
    for (auto & z : m_zoneManager)
        delete(z.second);
}

Zone* ZoneManager::GenerateZone(std::pair<int,int> p_lastZoneNum)
{
    return nullptr;
}

void ZoneManager::ChangeZoneUp(Player* p)
{
    if (p->GetPosition().y < 0.f)
    {
        m_lastZoneNum = m_zoneNum;
        m_zoneNum.second++;
        try {
            m_currentZone = m_zoneManager.at(m_zoneNum);
        } catch (const std::exception&) {
            m_zoneManager.insert( { m_zoneNum, new Zone(2, 3, 7, 4, p) } );
            m_currentZone = m_zoneManager.at(m_zoneNum);
        }
        *p->GetPositionAdress() += { 0.f, REGION_SIZE_Y - 10.f };
        p->UpdatePositions();
    }
}

void ZoneManager::ChangeZoneDown(Player* p)
{
    if (p->GetPosition().y > REGION_SIZE_Y)
    {
        m_lastZoneNum = m_zoneNum;
        m_zoneNum.second--;
        try {
            m_currentZone = m_zoneManager.at(m_zoneNum);
        } catch (const std::exception&) {
            m_zoneManager.insert( { m_zoneNum, new Zone(2, 3, 7, 4, p) } );
            m_currentZone = m_zoneManager.at(m_zoneNum);
        }
        *p->GetPositionAdress() -= { 0.f, REGION_SIZE_Y - 10.f};
        p->UpdatePositions();
    }
}

void ZoneManager::ChangeZoneLeft(Player* p)
{
    if (p->GetPosition().x < 0.f)
    {
        m_lastZoneNum = m_zoneNum;
        m_zoneNum.first--;
        try {
            m_currentZone = m_zoneManager.at(m_zoneNum);
        } catch (const std::exception&) {
            m_zoneManager.insert( { m_zoneNum, new Zone(2, 3, 4, 0, p) } );
            m_currentZone = m_zoneManager.at(m_zoneNum);
        }
        *p->GetPositionAdress() += { REGION_SIZE_X - 10.f, 0.f };
        p->UpdatePositions();
    }
}

void ZoneManager::ChangeZoneRight(Player* p)
{
    if (p->GetPosition().x > REGION_SIZE_X)
    {
        m_lastZoneNum = m_zoneNum;
        m_zoneNum.first++;
        try {
            m_currentZone = m_zoneManager.at(m_zoneNum);
        } catch (const std::exception&) {
            m_zoneManager.insert( { m_zoneNum, new Zone(2, 3, 7, 4, p) } );
            m_currentZone = m_zoneManager.at(m_zoneNum);
        }
        *p->GetPositionAdress() -= { REGION_SIZE_X - 10.f, 0.f };
        p->UpdatePositions();
    }
}

