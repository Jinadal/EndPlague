#include "IASeguimiento.h"
#include "CollisionComponent.h"
#include "MovementComponent.h"
#include "CollisionManager.h"
#include <iostream>



bool CheckX::run()
{

   if(main->getX() > (owner->getX()+ owner->getComponent<CollisionComponent>()->width_)){
       return true;
   }

   return false;
}

bool CheckXwid::run()
{
   // std::cout<< "MAIN X + WIDTH  "<< (main->getX() + main->getComponent<CollisionComponent>()->width_) << "\n";
  //  std::cout << "owner X  " << owner->getX() << "\n";

    if((main->getX() + main->getComponent<CollisionComponent>()->width_) < (owner->getX()+owner->getComponent<CollisionComponent>()->width_)){
        return true;
    }

    return false;
}


bool CheckY::run()
{

   if(main->getY() < (owner->getY()+ owner->getComponent<CollisionComponent>()->height_)){
       return true;
   }

   return false;
}

bool CheckYhei::run()
{

    if((main->getY() + main->getComponent<CollisionComponent>()->height_) > owner->getY()){
        return true;
    }

    return false;
}