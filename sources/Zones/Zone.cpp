//
// Created by scott on 4/2/2021.
//

#include "Zone.h"
#include "Objects/MovingObj.h"
#include "meta.h"
#include "Core/Drawer.h"



Zone::Zone(int nbRects, int nbLosanges, int nbOcts, int nbMovs, Player* p)
{
    m_entityVector.reserve(nbRects + nbLosanges + nbOcts + 1);
    m_rectObjectVector.reserve(nbRects);
    m_losangeObjectVector.reserve(nbLosanges);
    m_movingObjectVector.reserve(nbMovs + 1);
    m_octObjectVector.reserve(nbOcts);

    m_entityVector.push_back(p); m_movingObjectVector.push_back(p);
    for (int i = 0; i < nbRects; i++)
    {
        m_rectObjectVector.push_back(new RectangleObj(RandomPoint(), "empty", 0.f, 110.f, 190.f));
        m_entityVector.push_back(m_rectObjectVector[i]);
    }

    for (int i = 0; i < nbLosanges; i++)
    {
        m_losangeObjectVector.push_back(new LosangeObj(RandomPoint(), "empty", 0.f, 90.f, 120.f));
        m_entityVector.push_back(m_losangeObjectVector[i]);
    }

    for (int i = 0; i < nbOcts; i++)
    {
        if (i % 2) {
            m_octObjectVector.push_back(new OctogoneObj(RandomPoint(), "tree", 0.f, 90.f));
            m_entityVector.push_back(m_octObjectVector.back());
        } else {
            m_octObjectVector.push_back(new OctogoneObj(RandomPoint(), "rock", 0.f, 90.f));
            m_entityVector.push_back(m_octObjectVector.back());
        }

    }

    for (int i = 0; i < nbMovs; i++)
    {
        m_movingObjectVector.push_back(new MovingObj(RandomPoint(), "meanboys", 0.f, 90.f, .12f, 20));
        m_entityVector.push_back(m_movingObjectVector.back());
    }
}

Zone::~Zone()
{
    for (auto & so : m_octObjectVector)
        delete(so);
    for (auto & mo : m_movingObjectVector)
        delete(mo);
    for (auto & lo : m_losangeObjectVector)
        delete(lo);
    for (auto & e : m_entityVector)
        delete(e);
}

void Zone::MovingObjectsMovementRoutine()
{
    reinterpret_cast<Player*>(m_movingObjectVector.front())->MovementRoutine(m_octObjectVector,m_rectObjectVector,m_losangeObjectVector, m_movingObjectVector);
    for (int i = 1; i < m_movingObjectVector.size(); i++)
        m_movingObjectVector[i]->MovementRoutine(m_octObjectVector,m_rectObjectVector,m_losangeObjectVector, m_movingObjectVector);
}

void Zone::DrawGrid() // temporaire, i mean, almost everything in this file is temporaire
{
    int k = 0;
    for (int i = 0; i < REGION_SIZE_X; i += TILE_SIZE)
    {
        for (int j = 0; j < REGION_SIZE_Y; j += TILE_SIZE)
        {
            if (k % 2 == 0)
                Draw("g164", {(float)i, (float)j});
            else
                Draw("g264", {(float)i, (float)j});
            k++;
        }
        k++;
    }
}

void Zone::DrawTextures()
{
    for (auto & e : m_entityVector)
        e->DrawTexture();
}

void Zone::DrawRects()
{
    for (auto & ro : m_rectObjectVector)
        ro->DrawRect();
}

void Zone::DrawLosanges()
{
    for (auto & lo : m_losangeObjectVector)
        lo->DrawLosa();
}

void Zone::DrawRayons()
{
    for (auto & e : m_entityVector)
        e->DrawRayon();
}

void Zone::DrawBigRayons()
{
    for (auto & e : m_entityVector)
        e->DrawBigRayon();
}

void Zone::DrawOcts()
{
    for (auto & oo : m_octObjectVector)
        oo->DrawOct();
}

void Zone::DrawStars()
{
    for (auto & mo : m_movingObjectVector)
        mo->DrawStar();
}
