#include "IAPlanificacion.h"
#include <cmath>
#include <ctime> 
#include <cstdlib>
#include "IAComponent.h"
#include "BPhysicComponent.h"
#include "ShootComponent.h"
#include "GameObject.h"

/*
Salta si el personaje entra a menos de 10 unidades de distancia de portador de la ia

calcula las distancias entre los centros y devuelve true
*/
bool IA_Plan_InSight::run()
{

    float dx = main->getX() - owner->getX();
    float dy = main->getY() - owner->getY();

    if(fabs(dx) <= 10  && fabs(dy) <= 10){
        if(main==PhysicBullet::getInstance()->rayTest(owner->getX(),owner->getY(), owner->getZ(),owner->getRZ())
            && main==PhysicBullet::getInstance()->rayTest(owner->getX(),owner->getY(), owner->getZ(),owner->getRZ()+1)
            && main==PhysicBullet::getInstance()->rayTest(owner->getX(),owner->getY(), owner->getZ(),owner->getRZ()-1))
        {
            owner->getComponent<ShootComponent>()->shoot();
        }
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

bool IA_Plan_HaveWaypoint::run()
{
    if(!owner->getComponent<IAComponent>()->hasWaypoint )return true;

    return false;
}