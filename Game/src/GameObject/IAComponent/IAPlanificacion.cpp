#include "IAPlanificacion.h"
#include <cmath>
#include <ctime> 
#include <cstdlib> 
#include <iostream>
#include "IAComponent.h"
#include "MovementComponent.h"


bool IA_Plan_InSight::run()
{

    float dx = main->getX() - owner->getX();
    float dy = main->getY() - owner->getY();

    if(fabs(dx) <= 250 && fabs(dy) <= 250){
        
        ///std::cout << "PERSONAJE DETECTADO!!! \n";
         return true;
    }

        //std::cout << "PERSONAJE PERDIDO!!! \n";

    return false;


}

bool IA_Plan_DidICollide::run()
{

    if(owner->getComponent<IAComponent>()->didIcollide){
        owner->getComponent<IAComponent>()->didIcollide = false;
        return true;
    }

    return false;
}

bool IA_Plan_ChangeDirection::run()
{

    std::srand((unsigned) time(0));
    int i = (rand()%4)+1;
    if(i ==1){
        owner->getComponent<MovementComponent>()->moveObject(0,1);
        return true;
    }
      if(i ==2){
        owner->getComponent<MovementComponent>()->moveObject(0,-1);
        return true;
    }
      if(i ==3){
        owner->getComponent<MovementComponent>()->moveObject(1,0);
        return true;
    }
      if(i ==4){
        owner->getComponent<MovementComponent>()->moveObject(-1,0);
        return true;
    }

return false;

}