#include "WellManager.h"
#include "GameObject.h"
#include "WellComponent.h"

WellManager* WellManager::only_instance = nullptr;

void WellManager::createComponent(GameObject* owner)
{
    components.push_back(new WellComponent(owner, this));
    owner->addComponent(components[components.size()-1]);
}