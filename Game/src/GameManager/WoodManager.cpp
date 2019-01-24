#include "WoodManager.h"
#include "GameObject.h"
#include "WoodComponent.h"

WoodManager* WoodManager::only_instance = NULL;

void WoodManager::createComponent(GameObject* owner, float life)
{
    components.push_back(new WoodComponent(owner, this, life));
    owner->addComponent(components[components.size()-1]);
}

void WoodManager::updateAll(float dt)
{
    for(std::size_t i = 0; i<components.size(); i++)
    {
        ((WoodComponent*)components[i])->update(dt);
    }
}