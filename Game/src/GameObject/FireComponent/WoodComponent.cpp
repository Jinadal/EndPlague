#include "WoodComponent.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "SpawnComponent.h"
#include "GameValues.h"
#include "ProjectileComponent.h"
#include "SpecificSoundEvent.h"
#include <iostream>
#include <sstream>

void WoodComponent::update(float dt)
{
    if(burning)
    {
        life-=(dt*gv::FIRE_DAMMAGE);
    }
    if(life<0.f)
    {

        const void * address = static_cast<const void*>(this);
        std::stringstream ss;
        ss << address;  
        std::string name = ss.str();
        FireSoundEvent * s = ((FireSoundEvent*)SoundSystem::getInstance()->getEvent(name));
        s->stop(); 
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
     std::cout << "Sonido arranca"<< this <<"\n";
        FireSoundEvent * s = new FireSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("sburn"));
        const void * address = static_cast<const void*>(this);
        std::stringstream ss;
        ss << address;  
        std::string name = ss.str();
        SoundSystem::getInstance()->saveEvent(s, name); //guardar id como nombre de  la instancia
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

        const void * address = static_cast<const void*>(this);
        std::stringstream ss;
        ss << address;  
        std::string name = ss.str();
        FireSoundEvent * s = ((FireSoundEvent*)SoundSystem::getInstance()->getEvent(name));
        s->stop(); 
    }
}


void WoodComponent::dealDamage(ProjectileComponent* projectile)
{
    if(projectile && projectile->getTeam()!=team)
    {
        if(!burning)
            setBurning(true);
        HitSoundEvent * s = new HitSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("shit"));
        s->setPosition({gameObject->getX(), gameObject->getY(), gameObject->getZ()});
        s->setVolume(5);
        s->start();

        life -= projectile->getDamage();
    }
}