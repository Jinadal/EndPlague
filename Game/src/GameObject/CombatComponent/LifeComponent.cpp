#include <LifeComponent.h>
#include <iostream>

void LifeComponent::looseLife(float d){     //Gets by parametre a int damage from the attacker
    life-=(d*(1-shield));                    //Sets decreased life
    if(life<=0){
        gameObject->setKill(true);
    }
}

void LifeComponent::addLife(float l){
    life+=l;
}