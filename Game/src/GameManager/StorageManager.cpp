#include "StorageManager.h"
#include <iostream>


StorageManager* StorageManager::only_instance = NULL;


void StorageManager::createComponent(GameObject *owner){
    components.push_back(new StorageComponent(owner, this));
    owner->addComponent(components[components.size()-1]);
}


void StorageManager::updateAll(float dt)
{
    
}