#include "DropperManager.h"
#include "GameObject.h"
#include "DropperComponent.h"

DropperManager* DropperManager::only_instance = NULL;

void DropperManager::createComponent(GameObject* owner)
{
    components.push_back(new DropperComponent(owner, this));
    owner->addComponent(components[components.size()-1]);
}
