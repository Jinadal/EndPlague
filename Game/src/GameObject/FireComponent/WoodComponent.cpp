#include "WoodComponent.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "SpawnComponent.h"
#include "GameValues.h"
#include "ProjectileComponent.h"
#include "SpecificSoundEvent.h"

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
    
    
        FireSoundEvent * s = new FireSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("sburn"));
        SoundSystem::getInstance()->saveEvent(s, "sburn");
        s->setPosition({gameObject->getX(), gameObject->getY(), gameObject->getZ()});
        s->setVolume(5);
        s->start();
    

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

        FireSoundEvent * s = ((FireSoundEvent*)SoundSystem::getInstance()->getEvent("sburn"));
        s->stop(); 
    }
}


void WoodComponent::dealDamage(ProjectileComponent* projectile)
{
    if(projectile && projectile->getTeam()!=team)
    {
        setBurning(true);
        HitSoundEvent * s = new HitSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("shit"));
        s->setPosition({gameObject->getX(), gameObject->getY(), gameObject->getZ()});
        s->setVolume(5);
        s->start();

        life -= projectile->getDamage();
    }
}