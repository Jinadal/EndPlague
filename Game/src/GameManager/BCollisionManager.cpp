#include "BCollisionManager.h"

BCollisionManager* only_instance = NULL;

void BCollisionManager::createComponent(GameObject* owner, float xsize, float ysize, float zsize, float mass)
{
    components.push_back(new BCollisionComponent(owner, this, xsize, ysize, zsize, mass));
    owner->addComponent(components[components.size()-1]);
}