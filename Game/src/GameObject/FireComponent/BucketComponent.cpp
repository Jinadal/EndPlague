#include "BucketComponent.h"
#include "WoodComponent.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "SpecificSoundEvent.h"
#include <sstream>


void BucketComponent::fillBucket(WellComponent* wc)
{
    if(wc)
    {
        water=true;
        gameObject->getComponent<RenderComponent>()->setTexture((char*)"res/blue.bmp");

        WatergetSoundEvent * s = new WatergetSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("waterget"));
        const void * address = static_cast<const void*>(this);
        std::stringstream ss;
        ss << address;  
        std::string name = ss.str();
        SoundSystem::getInstance()->saveEvent(s, name); 
        s->setPosition({gameObject->getX(), gameObject->getY(), gameObject->getZ()});
        s->setVolume(5);
        s->start();

        delete s;
    }
}

void BucketComponent::dropBucket(WoodComponent* wc)
{
    if(wc && wc->getBurning())
    {
        if(water)
        {
            wc->addBucket();
            gameObject->getComponent<RenderComponent>()->setTexture((char*)"");
            water = false;
        }
    }
}