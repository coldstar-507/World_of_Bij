
#include "Drawer.h"

#include "Texture/TextureBank.h"
#include "Engine.h"
#include "Camera.h"

void Draw(const std::string & p_textureID, Vector2 p_texturePosition, float p_angle, SDL_FPoint* p_center)
{
    SDL_FRect dstRect = {
            ( (p_texturePosition.x - Camera::Position().x) * Camera::CurrentZoom() ) + Camera::Center().x,
            ( (p_texturePosition.y - Camera::Position().y) * Camera::CurrentZoom() ) + Camera::Center().y,
            (float) TextureBank::GetTexture(p_textureID)->GetWidth() * Camera::CurrentZoom(),
            (float) TextureBank::GetTexture(p_textureID)->GetHeight() * Camera::CurrentZoom()
    };
    SDL_RenderCopyExF(
            Engine::GetRenderer(),
            TextureBank::GetTexture(p_textureID)->GetTexture(),
            nullptr,
            &dstRect,
            p_angle,
            p_center,
            SDL_FLIP_NONE
            );
}

void DrawRectangle(const Quad & p_quad) // quad is calculated with object position so no need for a vec2 position
{
    SDL_FRect rect = {
        ( (p_quad.p3.x - Camera::Position().x) * Camera::CurrentZoom() ) + Camera::Center().x,
        ( (p_quad.p3.y - Camera::Position().y) * Camera::CurrentZoom() ) + Camera::Center().y,
        (p_quad.p1.x - p_quad.p3.x) * Camera::CurrentZoom(),
        (p_quad.p1.y - p_quad.p3.y) * Camera::CurrentZoom()
    };
    SDL_RenderDrawRectF(Engine::GetRenderer(), &rect);
}


void DrawCircle(const Vector2 & centre, const float rayon)
{
   const int diameter = (rayon * 2);

   int x = (rayon - 1);
   int y = 0;
   int tx = 1;
   int ty = 1;
   int error = (tx - diameter);

   while (x >= y)
   {
      //  Each of the following renders an octant of the circle
       SDL_RenderDrawPoint(Engine::GetRenderer(), (((centre.x + x) - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, (((centre.y - y) - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y);
       SDL_RenderDrawPoint(Engine::GetRenderer(), (((centre.x + x) - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, (((centre.y + y) - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y);
       SDL_RenderDrawPoint(Engine::GetRenderer(), (((centre.x - x) - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, (((centre.y - y) - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y);
       SDL_RenderDrawPoint(Engine::GetRenderer(), (((centre.x - x) - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, (((centre.y + y) - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y);
       SDL_RenderDrawPoint(Engine::GetRenderer(), (((centre.x + y) - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, (((centre.y - x) - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y);
       SDL_RenderDrawPoint(Engine::GetRenderer(), (((centre.x + y) - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, (((centre.y + x) - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y);
       SDL_RenderDrawPoint(Engine::GetRenderer(), (((centre.x - y) - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, (((centre.y - x) - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y);
       SDL_RenderDrawPoint(Engine::GetRenderer(), (((centre.x - y) - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, (((centre.y + x) - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y);
      if (error <= 0)
      {
         ++y;
         error += ty;
         ty += 2;
      }

      if (error > 0)
      {
         --x;
         tx += 2;
         error += (tx - diameter);
      }
   }
}

void DrawLosange(const Quad & p_los)
{
    SDL_RenderDrawLineF(Engine::GetRenderer(), Camera::TransformX(p_los.p1.x), Camera::TransformY(p_los.p1.y), Camera::TransformX(p_los.p2.x), Camera::TransformY(p_los.p2.y));
    SDL_RenderDrawLineF(Engine::GetRenderer(), Camera::TransformX(p_los.p2.x), Camera::TransformY(p_los.p2.y), Camera::TransformX(p_los.p3.x), Camera::TransformY(p_los.p3.y));
    SDL_RenderDrawLineF(Engine::GetRenderer(), Camera::TransformX(p_los.p3.x), Camera::TransformY(p_los.p3.y), Camera::TransformX(p_los.p4.x), Camera::TransformY(p_los.p4.y));
    SDL_RenderDrawLineF(Engine::GetRenderer(), Camera::TransformX(p_los.p4.x), Camera::TransformY(p_los.p4.y), Camera::TransformX(p_los.p1.x), Camera::TransformY(p_los.p1.y));
}

void DrawOctogone(const Octogone &p_oct)
{

    SDL_RenderDrawLineF(Engine::GetRenderer(), ((p_oct.p1.x - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, ((p_oct.p1.y - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y, ((p_oct.p2.x - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, ((p_oct.p2.y - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y);
    SDL_RenderDrawLineF(Engine::GetRenderer(), ((p_oct.p2.x - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, ((p_oct.p2.y - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y, ((p_oct.p3.x - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, ((p_oct.p3.y - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y);
    SDL_RenderDrawLineF(Engine::GetRenderer(), ((p_oct.p3.x - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, ((p_oct.p3.y - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y, ((p_oct.p4.x - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, ((p_oct.p4.y - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y);
    SDL_RenderDrawLineF(Engine::GetRenderer(), ((p_oct.p4.x - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, ((p_oct.p4.y - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y, ((p_oct.p5.x - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, ((p_oct.p5.y - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y);
    SDL_RenderDrawLineF(Engine::GetRenderer(), ((p_oct.p5.x - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, ((p_oct.p5.y - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y, ((p_oct.p6.x - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, ((p_oct.p6.y - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y);
    SDL_RenderDrawLineF(Engine::GetRenderer(), ((p_oct.p6.x - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, ((p_oct.p6.y - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y, ((p_oct.p7.x - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, ((p_oct.p7.y - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y);
    SDL_RenderDrawLineF(Engine::GetRenderer(), ((p_oct.p7.x - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, ((p_oct.p7.y - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y, ((p_oct.p8.x - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, ((p_oct.p8.y - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y);
    SDL_RenderDrawLineF(Engine::GetRenderer(), ((p_oct.p8.x - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, ((p_oct.p8.y - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y, ((p_oct.p1.x - Camera::Position().x) * Camera::CurrentZoom()) + Camera::Center().x, ((p_oct.p1.y - Camera::Position().y) * Camera::CurrentZoom()) + Camera::Center().y);

    /*

    SDL_RenderDrawLineF(Engine::GetRenderer(), Camera::TransformX(p_oct.p1.x), Camera::TransformY(p_oct.p1.y), Camera::TransformX(p_oct.p2.x), Camera::TransformY(p_oct.p2.y));
    SDL_RenderDrawLineF(Engine::GetRenderer(), Camera::TransformX(p_oct.p2.x), Camera::TransformY(p_oct.p2.y), Camera::TransformX(p_oct.p3.x), Camera::TransformY(p_oct.p3.y));
    SDL_RenderDrawLineF(Engine::GetRenderer(), Camera::TransformX(p_oct.p3.x), Camera::TransformY(p_oct.p3.y), Camera::TransformX(p_oct.p4.x), Camera::TransformY(p_oct.p4.y));
    SDL_RenderDrawLineF(Engine::GetRenderer(), Camera::TransformX(p_oct.p4.x), Camera::TransformY(p_oct.p4.y), Camera::TransformX(p_oct.p5.x), Camera::TransformY(p_oct.p5.y));
    SDL_RenderDrawLineF(Engine::GetRenderer(), Camera::TransformX(p_oct.p5.x), Camera::TransformY(p_oct.p5.y), Camera::TransformX(p_oct.p6.x), Camera::TransformY(p_oct.p6.y));
    SDL_RenderDrawLineF(Engine::GetRenderer(), Camera::TransformX(p_oct.p6.x), Camera::TransformY(p_oct.p6.y), Camera::TransformX(p_oct.p7.x), Camera::TransformY(p_oct.p7.y));
    SDL_RenderDrawLineF(Engine::GetRenderer(), Camera::TransformX(p_oct.p7.x), Camera::TransformY(p_oct.p7.y), Camera::TransformX(p_oct.p8.x), Camera::TransformY(p_oct.p8.y));
    SDL_RenderDrawLineF(Engine::GetRenderer(), Camera::TransformX(p_oct.p8.x), Camera::TransformY(p_oct.p8.y), Camera::TransformX(p_oct.p1.x), Camera::TransformY(p_oct.p1.y));

    */
}
