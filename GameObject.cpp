#include "GameObject.h"

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

void GameObject::Process(double delta)
{
    xpos++*delta;
    ypos++*delta;

    //set image's proper height and width otherwise sprite won't be visible
    srcRect.h = 1170; 
    srcRect.w = 870;
    srcRect.x= 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.h = srcRect.h /4;
    destRect.w = srcRect.w /4;
}

void GameObject::ObjectRender()
{
    SDL_RenderCopy(Game::renderer, ObjectTexture, &srcRect, &destRect);
}