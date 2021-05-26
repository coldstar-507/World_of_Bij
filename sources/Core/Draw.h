#ifndef WOB_DRAW_H
#define WOB_DRAW_H

#include "2DPhysics/Math.h"
#include "SDL.h"
#include <string>

void Draw(const std::string & p_textureID, Vector2 p_texturePosition, float p_angle = 0.f, SDL_FPoint* p_center = nullptr);

void DrawRectangle(const Quad & p_quad); // quad is calculated with object position so no need for a vec2 position

void DrawCircle(const Vector2 & centre, const float rayon);

void DrawLosange(const Quad & p_los);

void DrawOctogone(const Octogone & p_oct);

#endif // WOB_DRAW_H
