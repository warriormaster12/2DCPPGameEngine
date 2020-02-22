#pragma once

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "GameObject.h"
#include "World.h"
#include "TextureManager.h"



class Game
{
    public:
        Game();
        ~Game();

        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        
        void EventManager();
        void update();
        void render();
        void deltaT();
        void clean();

        bool running() {return isRunning;}

        static SDL_Renderer *renderer;
        
        
        

    private:
        bool isRunning;
        SDL_Window *window;
        Uint64 NOW = SDL_GetPerformanceCounter();
        Uint64 LAST = 0;
        double DeltaTime;
};

