#include "GameResource.h"
#include <iostream>

GameResource* GameResource::only_instance = NULL;

GameObject* GameResource::createGameObject(float x, float y, float z, float rz){
    gameobjects.push_back(new GameObject(x, y, z, rz));
    return gameobjects[gameobjects.size() - 1];
}

void GameResource::updateAll(){
    
    std::vector<GameObject*>::iterator it;
    for(it = gameobjects.begin(); it!=gameobjects.end(); it++){
        GameObject* go = *it;
        if(go->getKill()){
            std::cout<<"Antes de borrar: "<<go<<"\n";
            delete go;
            //*it = nullptr;
            std::cout<<"Despues de borrar\n";
            //it=gameobjects.erase(it);
            //it--;
        }
        it = gameobjects.erase(it);
    }
}