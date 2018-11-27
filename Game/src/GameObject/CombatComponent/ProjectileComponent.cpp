#include <ProjectileComponent.h>
#include <GameObject.h>
#include <LifeComponent.h>

void ProjectileComponent::dealDamage(GameObject* v){    //Gets a pointer to GameObject v to deal damage to it
    v->getComponent<LifeComponent*>()->looseLife(damage);   // GameObject v (victim) gets its component life 
                                                            // and calls looselife passing the proyectile parametre damage
}