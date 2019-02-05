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
    float p rand()/(RAND_MAX/(100.f)); 

    if(p<P_ITEM1){
        fabric->createItem(gameObject->getX(),
                            gameObject->getY(),
                            gameObject->getZ(),
                            gameObject->getRZ(),
                            ITEM_1);
    }else if(p<P_ITEM2){
        fabric->createItem(gameObject->getX(),
                            gameObject->getY(),
                            gameObject->getZ(),
                            gameObject->getRZ(),
                            ITEM_2);
    }else if(p<P_ITEM3){
        fabric->createItem(gameObject->getX(),
                            gameObject->getY(),
                            gameObject->getZ(),
                            gameObject->getRZ(),
                            ITEM_3);
    }

    delete fabric;
}