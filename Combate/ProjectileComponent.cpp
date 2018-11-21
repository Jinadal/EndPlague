#include <ProjectileComponent.h>
#include <GameObject.h>
#include <LifeComponent.h>

void ProjectileComponent::dealDamage(GameObject* v){
    v->getComponent<LifeComponent*>()->looseLife(damage);
}