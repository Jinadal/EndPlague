#include "StorageManager.h"
#include <iostream>


StorageManager* StorageManager::only_instance = NULL;


void StorageManager::createComponent(GameObject *owner, float cadencia){
    components.push_back(new StorageComponent(owner, this, cadencia));
    owner->addComponent(components[components.size()-1]);
}