#include "GameResource.h"
#include <iostream>

GameResource* GameResource::only_instance = NULL;

GameResource::~GameResource()
{
    for(std::size_t i = 0; i<gameobjects.size(); i++)
    {
        delete gameobjects[i];
    }
    only_instance=NULL;
}

GameObject* GameResource::createGameObject(float x, float y, float z, float rz)
{
    gameobjects.push_back(new GameObject(x, y, z, rz));
    return gameobjects[gameobjects.size() - 1];
}

void GameResource::updateAll()
{
    std::vector<GameObject*>::iterator it = gameobjects.begin();
    for(std::size_t i = 0; i<gameobjects.size(); i++)
    {
        GameObject* g = *it;
        if(g->getKill())
        {
            delete g;
            it = gameobjects.erase(it);
            i--;

        } else
            it++;
    }

}