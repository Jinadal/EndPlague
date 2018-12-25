#include "IAMovimiento.h"
#include "BPhysicComponent.h"
#include <iostream>

bool Pared::run(){
   // std::cout<< "invoco con ->  " << owner->getComponent<CollisionComponent>() << "\n";

    //if( ((CollisionManager*)owner->getComponent<CollisionComponent>()->getManager())->checkSingle(owner->getComponent<CollisionComponent>())){
       // std::cout << "PARED SALTA \n";

    //    return true;
    //}

return false;
    
}


bool MoverArriba::run(){


    owner->getComponent<BPhysicComponent>()->moveObject(0,1,0,main->getX(),main->getY());
    owner->getComponent<BPhysicComponent>()->setvMax(2.f);

    return true;
}


bool MoverAbajo::run(){


    owner->getComponent<BPhysicComponent>()->moveObject(0,-1,0,main->getX(),main->getY());
    owner->getComponent<BPhysicComponent>()->setvMax(2.f);

    return true;
}
bool MoverIzda::run(){


    owner->getComponent<BPhysicComponent>()->moveObject(-1,0,0,main->getX(),main->getY());
    owner->getComponent<BPhysicComponent>()->setvMax(2.f);

    
    return true;
}
bool MoverDcha::run(){


    owner->getComponent<BPhysicComponent>()->moveObject(1,0,0,main->getX(),main->getY());
    owner->getComponent<BPhysicComponent>()->setvMax(2.f);

    return true;
}