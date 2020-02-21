#include "World.h"


GameObject* player;

void World::create_world()
{
    player = new GameObject();
}

void World::render_world()
{
    player->ObjectRender();
}

void World::update_world(double delta)
{
    player->Process(delta);
}