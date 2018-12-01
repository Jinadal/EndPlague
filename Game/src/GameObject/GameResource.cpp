#include "GameResource.h"
#include <iostream>

GameResource* GameResource::only_instance = NULL;

GameObject* GameResource::createGameObject(float x, float y, float z, float rz){
    gameobjects.push_back(new GameObject(x, y, z, rz));
    return gameobjects[gameobjects.size() - 1];
}

void GameResource::updateAll(){
    //std::cout<<"GameObjects: ";
    for(int i=0; i<gameobjects.size(); i++)
        //std::cout<<gameobjects[i];

    //std::cout<<"\n";
    if(deleted)return;
    std::vector<GameObject*>::iterator it;
    for(it = gameobjects.begin(); it!=gameobjects.end(); it++){
        GameObject* go = *it;
        if(go->getKill()){
            std::cout<<"Antes de borrar: "<<go<<"\n";
            delete go;
            //*it = nullptr;
            deleted=true;
            std::cout<<"Despues de borrar\n";
            //it=gameobjects.erase(it);
            //it--;
        }
    }
}