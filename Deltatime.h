#pragma once

#include "Game.h"

class DeltaT
{
public: 
    DeltaT(double DeltaTime);

private: 
    Uint64 NOW, LAST;

};