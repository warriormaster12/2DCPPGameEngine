#pragma once

#include "Game.h"

class TextureManager
{
    public: 
        static SDL_Texture* LoadTexture(const char* text_loc, SDL_Renderer* rend);

};
