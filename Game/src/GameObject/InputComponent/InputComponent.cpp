#include "InputComponent.h"
#include "InputFacade.h"
//#include "MovementComponent.h"
#include <iostream>
#include <irrlicht.h>







void InputComponent::pulseInput(InputFacade *interface)
{

    int enX = 0, enY = 0;

    if(interface->IsKeyDown((irr::EKEY_CODE)w_))
    {
        enY-=1;
    }
    if(interface->IsKeyDown((irr::EKEY_CODE)a_))
    {
        enX-=1;
    }
    if(interface->IsKeyDown((irr::EKEY_CODE)s_))
    {
        enY+=1;
        
    }
    if(interface->IsKeyDown((irr::EKEY_CODE)d_))
    {
        enX+=1;
        
    }

    std::cout<< "EnX : " << enX << "EnY : "<< enY << "\n";
    //gameObject->getComponent<MovementComponent*>()->moveObject(enX,enY);


}
