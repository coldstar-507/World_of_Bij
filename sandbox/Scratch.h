
//
// Created by scott on 4/5/2021.
//

#ifndef WOB1_SCRATCH_H
#define WOB1_SCRATCH_H

#include <cstdlib>
#include <cstdio>
#include "2DPhysics/Math.h"
#include <vector>
#include "meta.h"

std::vector<Vector2> points1,points2,points3;

Vector2 IsoTo2D(const Vector2& v)
{
    Vector2* tmpv = new Vector2;
    tmpv->x = (2 * v.y + v.x) / 2;
    tmpv->y = (2 * v.y - v.x) / 2;
    return *tmpv;
}

Vector2 TwoDToIso(const Vector2& v)
{
  Vector2* tmpv = new Vector2;
  tmpv->x = v.x - v.y;
  tmpv->y = (v.x + v.y) / 2;
  return *tmpv;
}

void DrawIsoGrid()
{
    int k = 0;
    for (int i = 0; i < REGION_SIZE_X; i += ISO_TILE_SIZE)
    {
        for (int j = 0; j < REGION_SIZE_Y; j += ISO_TILE_SIZE)
        {
            if (k % 2 == 0)
                TextureBank::Draw("ISODARKGREY64", TwoDToIso({(float)i, (float)j}));
            else
                TextureBank::Draw("ISOGREY64", TwoDToIso({(float)i, (float)j}));
            k++;
        }
        k++;
    }
}

void DrawGrid()
{
    int k = 0;
    for (int i = 0; i < REGION_SIZE_X; i += TILE_SIZE)
    {
        for (int j = 0; j < REGION_SIZE_Y; j += TILE_SIZE)
        {
            if (k % 2 == 0)
                TextureBank::Draw("DARKGREY64", {(float)i, (float)j});
            else
                TextureBank::Draw("GREY64", {(float)i, (float)j});
            k++;
        }
        k++;
    }
}

std::vector<Vector2> GeneratePoints(int nbPoints)
{
    std::vector<Vector2> points(nbPoints);
    for (int i = 0; i < nbPoints; i++)
    {
        points[i] = {(float) (rand() % REGION_SIZE_X), (float) (rand() % REGION_SIZE_Y) };
    }
    return points;
}

std::vector<Vector2> GenerateIsoPoints(int nbPoints)
{
    std::vector<Vector2> points(nbPoints);
    for (int i = 0; i < nbPoints; i++)
    {
        points[i] = TwoDToIso({(float) (rand() % REGION_SIZE_X), (float) (rand() % REGION_SIZE_Y) });
    }
    return points;
}

void DrawWorld(const std::vector<Vector2> & v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i % 2)
            TextureBank::Draw("tree", v[i]);
        else
            TextureBank::Draw("rock", v[i]);
    }
}


#endif //WOB1_SCRATCH_H
