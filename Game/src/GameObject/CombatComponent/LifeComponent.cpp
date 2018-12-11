#include <LifeComponent.h>
#include <iostream>

void LifeComponent::looseLife(float d){     //Gets by parametre a int damage from the attacker
    life-=d;    
    //std::cout<<"Life: "<<life <<"\n";                           //Sets decreased life
    if(life<=0){
<<<<<<< HEAD
=======
       // std::cout<<"Deleting life\n";
>>>>>>> Fabrics
        gameObject->setKill(true);
    }
}

void LifeComponent::addLife(float l){
    life+=l;
}