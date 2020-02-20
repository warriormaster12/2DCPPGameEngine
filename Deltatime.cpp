#include "Deltatime.h"

DeltaT::DeltaT(double DeltaTime)
{
    LAST = SDL_GetPerformanceCounter();
    NOW = SDL_GetPerformanceCounter();
    LAST = NOW;

    DeltaTime = (NOW - LAST) / (double)SDL_GetPerformanceFrequency();
}