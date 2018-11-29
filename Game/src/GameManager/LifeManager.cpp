#include "LifeManager.h"


LifeManager* LifeManager::only_instance = NULL;


void LifeManager::createComponent(GameObject *owner, float l)
{
    components.push_back(new LifeComponent(owner, this, l));
    owner->addComponent(components[components.size()-1]);
}