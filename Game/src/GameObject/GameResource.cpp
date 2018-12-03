#include "GameResource.h"

GameResource* GameResource::only_instance = NULL;

GameObject* GameResource::createGameObject(float x, float y, float z, float rz){
    gameobjects.push_back(new GameObject(x, y, z, rz));
    return gameobjects[gameobjects.size() - 1];
}

void GameResource::updateAll(){
    /*
    for(auto& pointer : gameobjects){
        if (*pointer->toKill()){
            delete pointer;
            pointer = nullptr;
        }
    }*/
    //gameobjects.erase(std::remove(gameobjects.begin(), gameobjects.end(), nullptr), gameobjects.end());
}