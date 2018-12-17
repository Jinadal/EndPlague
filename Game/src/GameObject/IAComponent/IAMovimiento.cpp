#include "IAMovimiento.h"
#include "CollisionComponent.h"
#include "MovementComponent.h"
#include "CollisionManager.h"
#include <iostream>

bool Pared::run(){
   // std::cout<< "invoco con ->  " << owner->getComponent<CollisionComponent>() << "\n";

    if( ((CollisionManager*)owner->getComponent<CollisionComponent>()->getManager())->checkSingle(owner->getComponent<CollisionComponent>())){
       // std::cout << "PARED SALTA \n";

        return true;
    }

return false;
    
}


bool MoverArriba::run(){


    owner->getComponent<MovementComponent>()->moveObject(0,1,main->getX(),main->getY());
    owner->getComponent<MovementComponent>()->setvMax(300.f);

    return true;
}


bool MoverAbajo::run(){


    owner->getComponent<MovementComponent>()->moveObject(0,-1,main->getX(),main->getY());
    owner->getComponent<MovementComponent>()->setvMax(300.f);

    return true;
}
bool MoverIzda::run(){


    owner->getComponent<MovementComponent>()->moveObject(-1,0,main->getX(),main->getY());
    owner->getComponent<MovementComponent>()->setvMax(300.f);

    
    return true;
}
bool MoverDcha::run(){


    owner->getComponent<MovementComponent>()->moveObject(1,0,main->getX(),main->getY());
    owner->getComponent<MovementComponent>()->setvMax(300.f);

    return true;
}