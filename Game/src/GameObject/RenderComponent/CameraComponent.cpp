#include "CameraComponent.h"
#include <iostream>

void CameraComponent::update()
{

    //Actualize the values of x, y, z || If the player doesnt move farther than dMAX, we dont move the camera
    float dx = x - gameObject->getX();
    float dy = y - gameObject->getY();        

    std::cout<<"\nADX: "<<abs(dx)<<", ADY: "<<abs(dy)<<"\n";
    std::cout<<"dMAX: "<<dMAX<<"\n";

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

    std::cout<<x<<y<<z<<"\n";
    node->update(x, y+20.f, z-600.f, x, y, z);
    //node->update(0, 0, -600, 0, 0, 0);
}

void CameraComponent::setFOV(float fov)
{
    node->setFOV(fov);
}