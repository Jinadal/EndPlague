#include <LifeComponent.h>
#include <iostream>

void LifeComponent::update(){
    int sl;
    sl = this->getLife();
}

void LifeComponent::looseLife(int d){
    int changelife;
    changelife = life - d;
    setLife(changelife);
}
