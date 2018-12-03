#include <ItemManager.h>



void ItemManager::createComponent(GameObject  *owner,int type){
    components.push_back(new ItemComponent(owner, this, type));
    owner->addComponent(components[components.size()-1]);
}