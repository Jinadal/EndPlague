#include "BPhysicComponent.h"


void BPhysicComponent::update()
{
    //Hola
    btVector3 Point = rbody->getCenterOfMassPosition();
    gameObject->setX(Point[0]);
    gameObject->setY(Point[1]);
    gameObject->setZ(Point[2]);
}

void BPhysicComponent::setVelocity(float x, float y, float z)
{
    rbody->setLinearVelocity(btVector3(x, y, z));
}