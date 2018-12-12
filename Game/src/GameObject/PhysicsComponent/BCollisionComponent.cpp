#include "BCollisionComponent.h"


void BCollisionComponent::update()
        {
            btTransform newTrans;
            newTrans.getOrigin() = (btVector3(gameObject->getX(), gameObject->getY(), gameObject->getZ()));
            rbody->getMotionState()->setWorldTransform(newTrans);
        }