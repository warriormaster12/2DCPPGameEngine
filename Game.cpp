#include "Game.h"

SDL_Texture* PlayerText;
SDL_Rect srcR, destR;
int cnt;

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
    SDL_Surface* tmpSurface = IMG_Load("Assets/SonicTestSprite.png");
    PlayerText = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
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

void Game::update()
{

    long last = 0;
    float deltaTime = 0.0;	
    long now = SDL_GetTicks();
    //deltatime is in seconds
    if (now > last) {
	    deltaTime = ((float)(now - last)) / 1000;
	    last = now;
    }
    cnt ++;
    std::cout<<deltaTime<<std::endl;
    destR.h=170;
    destR.w=170;
    destR.x=50*deltaTime;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, PlayerText, NULL, &destR);
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}