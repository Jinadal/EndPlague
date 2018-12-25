#include "ItemManager.h"
#include "ItemComponent.h"


ItemManager* ItemManager::only_instance = NULL;



void ItemManager::createComponent(GameObject  *owner,float type){
    components.push_back(new ItemComponent(owner, this, type));
    owner->addComponent(components[components.size()-1]);
}


