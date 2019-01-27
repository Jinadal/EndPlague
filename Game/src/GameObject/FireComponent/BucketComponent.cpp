#include "BucketComponent.h"
#include "WoodComponent.h"
#include "GameObject.h"
#include "RenderComponent.h"

void BucketComponent::fillBucket(WellComponent* wc)
{
    if(wc)
    {
        water=true;
        gameObject->getComponent<RenderComponent>()->setTexture((char*)"res/blue.bmp");
    }
}

void BucketComponent::dropBucket(WoodComponent* wc)
{
    if(wc)
    {
        if(water)
        {
            wc->addBucket();
            gameObject->getComponent<RenderComponent>()->setTexture((char*)"");
            water = false;
        }
    }
}