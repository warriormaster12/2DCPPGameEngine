#pragma once

#include "Game.h"


class GameObject
{
public:
    GameObject();
   ~GameObject();
   void Process(double delta);
   void ObjectRender();
   void Ready();
   float xpos;
   float ypos;
   SDL_Texture* ObjectTexture;
   const char* TextureDirectory;
   SDL_Rect srcRect, destRect;

};