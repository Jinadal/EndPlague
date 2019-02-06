#include "DropperComponent.h"
#include "GameObject.h"
#include <stdlib.h>

DropperComponent::~DropperComponent()
{
    dropItem();
}

void DropperComponent::dropItem()
{
    ItemFabric* fabric = new ItemFabric();
    float p = rand()/(RAND_MAX/(100.f)); 

    if(p<P_POTION){
        fabric->createItem(gameObject->getX(),
                            gameObject->getY(),
                            gameObject->getZ(),
                            gameObject->getRZ(),
                            POTION);
    }else if(p<AXE){
        fabric->createItem(gameObject->getX(),
                            gameObject->getY(),
                            gameObject->getZ(),
                            gameObject->getRZ(),
                            AXE);
    }else if(p<P_PEAK){
        fabric->createItem(gameObject->getX(),
                            gameObject->getY(),
                            gameObject->getZ(),
                            gameObject->getRZ(),
                            PEAK);
    }else if(p<P_CROSSBOW){
        fabric->createItem(gameObject->getX(),
                            gameObject->getY(),
                            gameObject->getZ(),
                            gameObject->getRZ(),
                            CROSSBOW);
    }else if(p<P_SHIELD){
        fabric->createItem(gameObject->getX(),
                            gameObject->getY(),
                            gameObject->getZ(),
                            gameObject->getRZ(),
                            SHIELD);
    }
    delete fabric;
}