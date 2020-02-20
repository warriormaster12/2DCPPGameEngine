#pragma once

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Deltatime.h"



class Game
{
    public:
        Game();
        ~Game();

        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        
        void EventManager();
        void update();
        void render();
        void clean();

        bool running() {return isRunning;}

        static SDL_Renderer *renderer;

    private:
        bool isRunning;
        SDL_Window *window;
};

