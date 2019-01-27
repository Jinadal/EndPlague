#include "BPhysicComponent.h"
#define PI 3.14159265


void BPhysicComponent::update()
{
    btVector3 Point = rbody->getCenterOfMassPosition();
    gameObject->setX(Point[0]);
    gameObject->setY(Point[1]);
    gameObject->setZ(Point[2]);

    btVector3 rotation = rbody->getTotalTorque();
    gameObject->setRX(rotation[0]);
    gameObject->setRY(rotation[1]);
    gameObject->setRZ(rotation[2]);

}

void BPhysicComponent::moveObject(float x, float y, float z, float tx, float ty)
{
    
    float vX, vY;
    if(x<0)
        vX = -1;
    else if(x==0)
        vX = 0;
    else if(x>0)
        vX = 1;

    if(y<0)
        vY = -1;
    else if(y==0)
        vY = 0;
    else if(y>0)
        vY = 1;

    //Comprobar vMax
    float length = sqrt(pow(vX, 2) + pow(vY, 2));
    if(length!=0.f){
        vX = (vX/length)*vMax;
        vY = (vY/length)*vMax;
    }else{
        vX=0.f;
        vY=0.f;
    }

    float rZ = atan2(gameObject->getY() - ty, gameObject->getX() - tx);
    rZ += PI/2.0;
    rZ = rZ * 180/PI;
    if (rZ < 0)
        rZ += 360;
    rbody->setLinearVelocity(btVector3(vX, vY, z));
    rbody->applyTorque(btVector3(0, 0, rZ));
}


void BPhysicComponent::setVelocity(float x, float y, float z)
{
    rbody->setLinearVelocity( btVector3(x, y, z) );
}