#include <iostream>

#include "ShootComponent.h"

void ShootComponent::Shoot(){
    bool s;
    s = getShooted();
    if(!s){
        setShooted(true);
        std::cout<<"He disparado"<<std::endl;
    }
}