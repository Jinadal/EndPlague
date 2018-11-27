#include "MovementComponent.h"
#include "GameObject.h"
#include <iostream>
#include <cmath>

MovementComponent::MovementComponent(GameObject* g) : Component(g){
    vX      = 0.f;
    vY      = 0.f;
    vZ      = 0.f;
    vMax    = 40.f;
    preX    = 0.f;
    preY    = 0.f;
    preZ    = 0.f;
}

void MovementComponent::update(float dt){
    //Comprobar vMax
    float length = sqrt(pow(vX, 2) + pow(vY, 2));
    //std::cout<<length<<"\n";
    if(length!=0.f){
        vX = (vX/length)*vMax;
        vY = (vY/length)*vMax;
    }else{
        vX=0.f;
        vY=0.f;
    }

    float rz = gameObject->getRZ();//No calculado el angulo

    preX=gameObject->getX();
    preY=gameObject->getY();
    preZ=gameObject->getZ();

    gameObject->setX(gameObject->getX() + vX*dt);
    gameObject->setY(gameObject->getY() + vY*dt);
    gameObject->setZ(gameObject->getZ() + vZ*dt);

    gameObject->setRZ(rz);
}

void MovementComponent::goBackX(){
    gameObject->setX(preX);
}

void MovementComponent::goBackY(){
    gameObject->setY(preY);
}


void MovementComponent::moveObject(int x, int y){
    if(x<0)
        this->vX = -1;
    else if(x==0)
        this->vX = 0;
    else if(x>0)
        this->vX = 1;

    if(y<0)
        this->vY = -1;
    else if(y==0)
        this->vY = 0;
    else if(y>0)
        this->vY = 1;
}