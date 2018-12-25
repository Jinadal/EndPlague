#include "IASeguimiento.h"
#include "BPhysicComponent.h"
#include <iostream>
#include <cmath>



bool IA_Seg_CheckXIzd::run()
{
    float dx = main->getX() - owner->getX();

   if(dx > 0){
       if(fabs(dx) > 3.f)
       return true;
   }

   return false;
}

bool IA_Seg_CheckXDer::run()
{
    float dx = main->getX() - owner->getX();
   
    if(dx <= 0){
       
       if(fabs(dx) > 3.f)
        return true;
    }

    return false;
}


bool IA_Seg_CheckYAbj::run()
{
    float dy = main->getY() - owner->getY();

   if(dy > 0){
       
       if(fabs(dy) > 3.f)
       return true;
   }

   return false;
}

bool IA_Seg_CheckYArr::run()
{
    float dy = main->getY() - owner->getY();

    if(dy <= 0){

       if(fabs(dy) > 3.f)
        return true;
    }

    return false;
}


bool IA_Seg_DifX::run()
{
    float dx = main->getX() - owner->getX();
    float dy = main->getY() - owner->getY();
    
    if(fabs(dx) >= fabs(dy)) return true;
    return false;
}

bool IA_Seg_DifY::run()
{
    float dx = main->getX() - owner->getX();
    float dy = main->getY() - owner->getY();
    
    if(fabs(dy) > fabs(dx)) return true;
    return false;
}





















/*

bool CheckX::run()
{

   if(main->getX() > (owner->getX()+ owner->getComponent<CollisionComponent>()->width_/2)){
       return true;
   }

   return false;
}

bool CheckXwid::run()
{
   // std::cout<< "MAIN X + WIDTH  "<< (main->getX() + main->getComponent<CollisionComponent>()->width_) << "\n";
  //  std::cout << "owner X  " << owner->getX() << "\n";

    if((main->getX() + main->getComponent<CollisionComponent>()->width_/2) < owner->getX()){
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
*/