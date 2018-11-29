#include <LifeComponent.h>
#include <iostream>

bool LifeComponent::looseLife(float d){     //Gets by parametre a int damage from the attacker
    life-=d;                                //Sets decreased life
    std::cout<<"Life: "<<life<<"\n";
    if(life<=0){
        gameObject->kill();
        return true;
    }
    return false;
}