#include "WoodComponent.h"
#include "GameObject.h"
#include "RenderComponent.h"

void WoodComponent::update(float dt)
{
    if(burning)
    {
        life-=(dt*FIRE_DAMMAGE);
    }
    if(life<0.f)
    {
        gameObject->setKill(true);
    }
}

void WoodComponent::setBurning(bool b){
    burning=b;
    if(b)//Cambiamos el color a rojo si esta ardiendo
    {
        gameObject->getComponent<RenderComponent>()->setTexture((char*)"res/red.bmp");
    }else//Cambiamos el color a rojo si esta ardiendo
    {
        gameObject->getComponent<RenderComponent>()->setTexture((char*)"res/green.bmp");
    }

}


void WoodComponent::addBucket()
{
    buckets++;
    if(buckets>=BUCKETS_NEDED){
        burning = false;
        buckets = 0;
        if(gameObject->getComponent<RenderComponent>())
        {
            gameObject->getComponent<RenderComponent>()->setTexture((char*)"res/green.bmp");
        }     
    }
}