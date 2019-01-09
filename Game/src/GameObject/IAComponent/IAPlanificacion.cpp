#include "IAPlanificacion.h"
#include <cmath>
#include <ctime> 
#include <cstdlib> 
#include <iostream>
#include "IAComponent.h"
#include "BPhysicComponent.h"
#include "ShootComponent.h"



bool IA_Plan_InSight::run()
{

    float dx = main->getX() - owner->getX();
    float dy = main->getY() - owner->getY();

    if(fabs(dx) <= 50  && fabs(dy) <= 10){
        owner->getComponent<ShootComponent>()->shoot();
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
        owner->getComponent<BPhysicComponent>()->moveObject(0,1,0, 0.f, 0.f);
        return true;
    }
      if(i ==2){
        owner->getComponent<BPhysicComponent>()->moveObject(0,-1,0, 0.f, 0.f);
        return true;
    }
      if(i ==3){
        owner->getComponent<BPhysicComponent>()->moveObject(1,0,0, 0.f, 0.f);
        return true;
    }
      if(i ==4){
        owner->getComponent<BPhysicComponent>()->moveObject(-1,0,0, 0.f, 0.f);
        return true;
    }

return false;

}