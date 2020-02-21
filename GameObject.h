#pragma once

#include "Game.h"


class GameObject
{
public:
    GameObject(const char* texturesheet, float x, float y);
   ~GameObject();
   void Process(double delta);
   void ObjectRender();
   void Ready();


};