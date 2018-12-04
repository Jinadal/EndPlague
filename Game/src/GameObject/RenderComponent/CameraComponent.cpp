#include "CameraComponent.h"

void CameraComponent::update()
{

    //Actualize the values of x, y, z || If the player doesnt move farther than dMAX, we dont move the camera
    float dx = x - gameObject->getX();
    float dy = y - gameObject->getY();        

    if(abs(dx)>dMAX)
        if(x<gameObject->getX())
            x=gameObject->getX()-dMAX;
        else if(x>gameObject->getX())
            x=gameObject->getX()+dMAX;

    if(abs(dy)>dMAX)
        if(y<gameObject->getY())
            y=gameObject->getY()-dMAX;
        else if(y>gameObject->getY())
            y=gameObject->getY()+dMAX;



    node->update(x, y+20.f, z-20.f, x, y, z);
}

void CameraComponent::setFOV(float fov)
{
    node->setFOV(fov);
}