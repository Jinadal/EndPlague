#include "LifeComponent.h"
#include "GameObject.h"

void LifeComponent::looseLife(float d){     //Gets by parametre a int damage from the attacker
    life-=(d*(1-shield));                    //Sets decreased life
}

void LifeComponent::addLife(float l){
    life+=l;
}


void LifeComponent::update(float dt)
{
    if(life<=0){
        gameObject->setKill(true);
    }

    if(!decreases)
        return;

    elapsedTime+=dt;
    if(elapsedTime>1.f)
    {
        elapsedTime = 0.f;
        life-=10.f;
    }
}