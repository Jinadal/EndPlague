#include "IASeguimiento.h"
#include "BPhysicComponent.h"
#include "RenderComponent.h"
#include <iostream>
#include <cmath>


bool IA_Seg_ToPlayer::run()
{
      float d = round(sqrt(pow(main->getX() - owner->getX(),2) + pow(main->getY() - owner->getY(),2)));
     
    
    float rZ = atan2(owner->getY() - main->getY(), owner->getX() - main->getX());
    rZ += PI/2.0;
    rZ = rZ * 180/PI;
    if (rZ < 0)
        rZ += 360;
    if(d< 4.f) {
        owner->getComponent<BPhysicComponent>()->setvMax(0.f);

    }else{
        owner->getComponent<BPhysicComponent>()->setvMax(3.f);
    }

    owner->getComponent<RenderComponent>()->setTexture((char*)"res/yelow.bmp");

    owner->getComponent<BPhysicComponent>()->setVelocity(rZ, true);
    return true;
}

