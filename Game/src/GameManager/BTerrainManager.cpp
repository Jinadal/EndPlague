#include "BTerrainManager.h"

BTerrainManager* BTerrainManager::only_instance = nullptr;

void BTerrainManager::updateAll(float dt){}

void BTerrainManager::createComponent(GameObject* owner, char* mesh){
    components.push_back(new BTerrainComponent(owner, this, mesh));
    owner->addComponent(components[components.size()-1]);
}