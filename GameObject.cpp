#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, float x, float y)
{
    ObjectTexture = TextureManager::LoadTexture(texturesheet);
    xpos = x;
    ypos = y;
}

void GameObject::Update()
{
    long last = 0;
    float deltaTime = 0.0;	
    long now = SDL_GetTicks();
    //deltatime is in seconds
    if (now > last) {
        deltaTime = ((float)(now - last)) / 1000;
        last = now;
   }

    xpos++*deltaTime;
    ypos++*deltaTime;

    //set image's proper height and width otherwise it won't work
    srcRect.h = 1170; 
    srcRect.w = 870;
    srcRect.x= 0;
    srcRect.y = 0;

    destRect.x = xpos/100;
    destRect.y = ypos/100;
    destRect.h = srcRect.h /4;
    destRect.w = srcRect.w /4;
}

void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, ObjectTexture, &srcRect, &destRect);
}