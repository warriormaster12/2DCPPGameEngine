#include "Game.h"



GameObject* player;

SDL_Renderer* Game::renderer = nullptr;


Game::Game()
{}

Game::~Game()
{}


void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
       flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
    {
        std::cout << "Subsystem Initialised!!..." << std::endl;

        window = SDL_CreateWindow(title,xpos,ypos,width,height,flags);
        if(window)
        {
            std::cout <<"Window created!" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
            std::cout <<"Renderer created!" << std::endl;
        }

        isRunning = true;
    }
    player = new GameObject("Assets/SonicTestSprite.png",0.0,0.0);
}


void Game::EventManager()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        
        default:
            break;
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    player->ObjectRender();
    SDL_RenderPresent(renderer);
}

void Game::update()
{
    player->Process(DeltaTime);
}

void Game::deltaT(double delta)
{
    DeltaTime = delta;
    LAST = SDL_GetPerformanceCounter();
    NOW = SDL_GetPerformanceCounter();
    LAST = NOW;

    delta = (NOW - LAST) / (double)SDL_GetPerformanceFrequency();
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}
