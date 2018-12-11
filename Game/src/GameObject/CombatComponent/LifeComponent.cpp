#include <LifeComponent.h>

void LifeComponent::looseLife(float d){     //Gets by parametre a int damage from the attacker
    life-=d;                                //Sets decreased life
    if(life<=0){
        gameObject->toKill();
    }
}

void LifeComponent::addLife(float l){
    life+=l;
}