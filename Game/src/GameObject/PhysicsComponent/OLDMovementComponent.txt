#include "MovementComponent.h"
#include "GameObject.h"
#include <cmath>
#include <iostream>

#define PI 3.14159265
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

    

    preX=gameObject->getX();
    preY=gameObject->getY();
    preZ=gameObject->getZ();

    gameObject->setX(gameObject->getX() + vX*dt);
    gameObject->setY(gameObject->getY() + vY*dt);
    gameObject->setZ(gameObject->getZ() + vZ*dt);

    gameObject->setRZ(rZ);
}

void MovementComponent::goBackX(){
    gameObject->setX(preX);
}

void MovementComponent::goBackY(){
    gameObject->setY(preY);
}


void MovementComponent::moveObject(int x, int y, float tx, float ty){
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


    rZ = atan2(gameObject->getY() - ty, gameObject->getX() - tx);
    rZ += PI/2.0;
    rZ = rZ * 180/PI;
    if (rZ < 0)
        rZ += 360;
}