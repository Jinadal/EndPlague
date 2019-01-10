#include "ItemManager.h"
#include "ItemComponent.h"


ItemManager* ItemManager::only_instance = NULL;



void ItemManager::createComponent(GameObject  *owner,ItemTypes type){
    components.push_back(new ItemComponent(owner, this, type));
    owner->addComponent(components[components.size()-1]);
}


void ItemManager::updateAll(float dt)
{

}

