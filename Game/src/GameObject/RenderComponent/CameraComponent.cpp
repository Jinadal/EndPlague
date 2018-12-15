#include "CameraComponent.h"
#include <iostream>

void CameraComponent::update(float dt)
{

    //Actualize the values of x, y, z || If the player doesnt move farther than dMAX, we dont move the camera
    float dx = x - gameObject->getX();
    float dy = y - gameObject->getY();

    //Smooth movement
    float vx = - dx * v;
    float vy = - dy * v;

    x += vx*dt; 
    y += vy*dt; 

    //If we want the player on the middle 
    /*   
    if(abs(dx)>dMAX)
    {
        if(x<gameObject->getX())
        {
            x=gameObject->getX()-dMAX;
        }
        else if(x>gameObject->getX())
        {
            x=gameObject->getX()+dMAX;
        }
    }

    if(abs(dy)>dMAX)
    {
        if(y<gameObject->getY())
        {
            y=gameObject->getY()-dMAX;
        }
        else if(y>gameObject->getY())
        {
            y=gameObject->getY()+dMAX;
        }
    }
    */

    node->update(x, y-100.f, z-800.f, x, y, z);
}

void CameraComponent::setFOV(float fov)
{
    node->setFOV(fov);
}