#include <LifeComponent.h>
#include <iostream>

void LifeComponent::looseLife(float d){     //Gets by parametre a int damage from the attacker
    life-=d;    
    std::cout<<"Life: "<<life <<"\n";                           //Sets decreased life
    if(life<=0){
        std::cout<<"Deleting life\n";
        gameObject->setKill(true);
    }
}