#pragma once

#include "Game.h"


class GameObject
{
public:
   GameObject(const char* texturesheet, float x, float y);
   ~GameObject();

   void Update();
   void Render();

private:

    float xpos;
    float ypos;

    SDL_Texture* ObjectTexture;
    SDL_Rect srcRect, destRect;

};