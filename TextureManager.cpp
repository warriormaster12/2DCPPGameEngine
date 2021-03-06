#include "TextureManager.h"


SDL_Texture* TextureManager::LoadTexture(const char* text_loc)
{
    SDL_Surface* tmpSurface = IMG_Load(text_loc);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return tex;
}