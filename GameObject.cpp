#include "GameObject.h"

DeltaT* delta;
double deltaTime;
float xpos;
float ypos;

SDL_Texture* ObjectTexture;
SDL_Rect srcRect, destRect;

GameObject::GameObject(const char* texturesheet, float x, float y)
{
    ObjectTexture = TextureManager::LoadTexture(texturesheet);
    xpos = x;
    ypos = y;
}

void Game::update()
{
    delta = new DeltaT(deltaTime);
    

    xpos++*deltaTime;
    ypos++*deltaTime;

    //set image's proper height and width otherwise it won't work
    srcRect.h = 1170; 
    srcRect.w = 870;
    srcRect.x= 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.h = srcRect.h /4;
    destRect.w = srcRect.w /4;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(Game::renderer, ObjectTexture, &srcRect, &destRect);
    SDL_RenderPresent(renderer);
}