#include "BPhysicComponent.h"



void BPhysicComponent::update()
{
    btVector3 Point = rbody->getCenterOfMassPosition();
    gameObject->setX(Point[0]);
    gameObject->setY(Point[1]);
    gameObject->setZ(Point[2]);

    btQuaternion mRotation;
    btTransform mTransform;
    mTransform = rbody->getWorldTransform();
    mRotation = mTransform.getRotation();
    btScalar yawZ, pitchY, rollX;
    mRotation.getEulerZYX(yawZ, pitchY, rollX);
    
	// roll (x-axis rotation)
	
    gameObject->setRX(rollX*180/PI);
    gameObject->setRY(pitchY*180/PI);
    gameObject->setRZ(yawZ*180/PI);

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

    btTransform tr = rbody->getWorldTransform();
    btQuaternion quat;
    quat.setEuler(0,0, rZ*PI/180); //or quat.setEulerZYX depending on the ordering you want
    tr.setRotation(quat);

    rbody->setWorldTransform(tr);

    //rbody->applyTorque(btVector3(0, 0, rZ));
}


void BPhysicComponent::setVelocity(float x, float y, float z)
{
    rbody->setLinearVelocity( btVector3(x, y, z) );
}