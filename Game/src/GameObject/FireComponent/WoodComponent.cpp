#include "WoodComponent.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "SpawnComponent.h"
#include "GameValues.h"
#include "ProjectileComponent.h"

void WoodComponent::update(float dt)
{
    if(burning)
    {
        life-=(dt*gv::FIRE_DAMMAGE);
    }
    if(life<0.f)
    {
        gameObject->setKill(true);
    }
}

void WoodComponent::setBurning(bool b){
    burning=b;
    if(gameObject->getComponent<SpawnComponent>() && gameObject->getComponent<SpawnComponent>()->isCuartel())
    {
        if(b)
        {
            gameObject->getComponent<RenderComponent>()->setTexture((char*)"res/tex/Cuartel_Fuego_Color.bmp");
        }else
        {
            gameObject->getComponent<RenderComponent>()->setTexture((char*)"res/tex/Cuartel_SColor.bmp");
        }
    }else{
        if(b)
        {
            gameObject->getComponent<RenderComponent>()->setTexture((char*)"res/tex/Casa_Fuego_Color.bmp");
        }else
        {
            gameObject->getComponent<RenderComponent>()->setTexture((char*)"res/tex/Casa_Color.bmp");
        }
    }
    

}

void WoodComponent::addBucket()
{
    buckets++;
    if(buckets>=gv::BUCKETS_NEDED){
        burning = false;
        buckets = 0;
        if(gameObject->getComponent<RenderComponent>())
        {
            gameObject->getComponent<RenderComponent>()->setTexture((char*)"res/green.bmp");
        }     
    }
}


void WoodComponent::dealDamage(ProjectileComponent* projectile)
{
    if(projectile && projectile->getTeam()!=team)
    {
        setBurning(true);
        life -= projectile->getDamage();
    }
}