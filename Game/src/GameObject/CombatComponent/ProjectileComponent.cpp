#include <ProjectileComponent.h>
#include <LifeComponent.h>

bool ProjectileComponent::dealDamage(LifeComponent* l){//Retrurns true if l kills his parent
    return l->looseLife(damage);
}

void ProjectileComponent::crush(){
    gameObject->kill();
}