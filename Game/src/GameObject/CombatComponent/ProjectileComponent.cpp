#include "ProjectileComponent.h"
#include "LifeComponent.h"
#include "GameObject.h"

void ProjectileComponent::dealDamage(LifeComponent* l){
    if(l && l->getTeam()!=team)
        l->looseLife(damage);
        
    gameObject->setKill(true);
}
