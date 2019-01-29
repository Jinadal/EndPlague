#include "IASeguimiento.h"
#include "BPhysicComponent.h"
#include "GameObject.h"
#include <cmath>


/*
Compruba si el jugador esta a su izda, eso es cuando  la diferencia en x da mayor que cero, por eso de que (por algun motivo) la x aumenta hacia la izda
*/
bool IA_Seg_CheckXIzd::run()
{
    float dx = main->getX() - owner->getX();

   if(dx > 0){
     //if(fabs(dx) > 3.f)
       return true;
   }

   return false;
}

//Compruba si el jugador esta a su derecha, eso es cuando la diferencia en x da menor o igual que cero,


bool IA_Seg_CheckXDer::run()
{
    float dx = main->getX() - owner->getX();
   
    if(dx <= 0){
       
      //if(fabs(dx) > 3.f)
        return true;
    }

    return false;
}

// Lo busca por debajo de el, aqui el eje Y tambien esta invertido

bool IA_Seg_CheckYAbj::run()
{
    float dy = main->getY() - owner->getY();

   if(dy > 0){
       
       //if(fabs(dy) > 3.f)
       return true;
   }
    
   return false;
}

// Busca la jugador por encima suyo

bool IA_Seg_CheckYArr::run()
{
    float dy = main->getY() - owner->getY();

    if(dy <= 0){

       //if(fabs(dy) > 3.f)
        return true;
    }

    return false;
}

//Según convenencia del guion. Mira si la distancia en x es mayor que en Y para enfatizar mas su recorrido 

bool IA_Seg_DifX::run()
{
    float dx = main->getX() - owner->getX();
    float dy = main->getY() - owner->getY();
    
    if(fabs(dx) >= fabs(dy)) return true;
    return false;
}

//Lo mismo que arriba pero al reves
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