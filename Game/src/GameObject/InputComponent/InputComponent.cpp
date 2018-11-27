#include "InputComponent.h"
#include "InputFacade.h"
//#include "MovementComponent.h"
#include <iostream>






void InputComponent::pulseInput(InputFacade *interface)
{

    int enX = 0, enY = 0;

    if(interface->IsKeyDown(w_))
    {
        enY-=1;
    }
    if(interface->IsKeyDown(a_))
    {
        enX-=1;
    }
    if(interface->IsKeyDown(s_))
    {
        enY+=1;
        
    }
    if(interface->IsKeyDown(d_))
    {
        enX+=1;
        
    }

    std::cout<< "EnX : " << enX << "EnY : "<< enY << "\n";
    //gameObject->getComponent<MovementComponent*>()->moveObject(enX,enY);


}
