#include <ProjectileManager.h>

ProjectileManager* ProjectileManager::only_instance = NULL;


void ProjectileManager::createComponent(GameObject *owner, float damage)
{
    components.push_back(new ProjectileComponent(owner, damage));
    owner->addComponent(components[components.size()-1]);
}

void ProjectileManager::createBullet(){}