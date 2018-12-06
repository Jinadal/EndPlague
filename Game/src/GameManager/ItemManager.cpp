#include "ItemManager.h"
#include "ItemComponent.h"
#include <iostream>


ItemManager* ItemManager::only_instance = NULL;



void ItemManager::createComponent(GameObject  *owner,float cadencia){
    std::cout<<"ME HE CREADO\n";
    components.push_back(new ItemComponent(owner, this, cadencia));
    owner->addComponent(components[components.size()-1]);
}


