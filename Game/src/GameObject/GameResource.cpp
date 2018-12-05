#include "GameResource.h"
#include <iostream>

GameResource* GameResource::only_instance = NULL;

GameObject* GameResource::createGameObject(float x, float y, float z, float rz){
    gameobjects.push_back(new GameObject(x, y, z, rz));
    return gameobjects[gameobjects.size() - 1];
}

void GameResource::updateAll(){
    for(std::vector<GameObject*>::iterator it = gameobjects.begin(); it!=gameobjects.end(); it++){
        std::cout<<"Try:\n";
        GameObject* g = *it;
        std::cout<<"a\n";
        if(g!=NULL && g->getKill()){
            std::cout<<"  KILL!  ";
            delete g;
            it = gameobjects.erase(it);
            std::cout<<"Killed\n";

        }
        std::cout<<"b\n";
    }
}