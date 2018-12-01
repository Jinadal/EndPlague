#include "ProjectileComponent.h"
#include "LifeComponent.h"
#include <iostream>

void ProjectileComponent::dealDamage(LifeComponent* l){
    if(l)
        l->looseLife(damage);

    gameObject->toKill();
    std::cout<<"Deleting pojectile\n";
}
