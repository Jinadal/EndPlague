#include "ProjectileManager.h"
#include "ProjectileComponent.h"
#include "GameObject.h"

ProjectileManager* ProjectileManager::only_instance = NULL;


void ProjectileManager::createComponent(GameObject *owner, float damage)
{
    components.push_back(new ProjectileComponent(owner, this, damage));
    owner->addComponent(components[components.size()-1]);
}


void ProjectileManager::updateAll(float dt)
{
    
}
