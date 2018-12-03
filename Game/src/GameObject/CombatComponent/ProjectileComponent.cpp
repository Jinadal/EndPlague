#include <ProjectileComponent.h>
#include <LifeComponent.h>

void ProjectileComponent::dealDamage(LifeComponent* l){
    if(l)
        l->looseLife(damage);

    gameObject->toKill();
}
