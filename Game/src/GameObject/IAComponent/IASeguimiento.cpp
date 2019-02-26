#include "IASeguimiento.h"
#include "BPhysicComponent.h"
#include "RenderComponent.h"
#include <iostream>
#include <cmath>


bool IA_Seg_ToPlayer::run()
{
    
    float rZ = atan2(owner->getY() - main->getY(), owner->getX() - main->getX());
    rZ += PI/2.0;
    rZ = rZ * 180/PI;
    if (rZ < 0)
        rZ += 360;
    owner->getComponent<BPhysicComponent>()->setvMax(3.f);

    owner->getComponent<RenderComponent>()->setTexture((char*)"res/yelow.bmp");

    owner->getComponent<BPhysicComponent>()->setVelocity(rZ, true);
    return true;
}