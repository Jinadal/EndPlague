#include "BucketComponent.h"
#include "WellComponent.h"
#include "WoodComponent.h"

void BucketComponent::fillBucket(WellComponent* wc)
{
    if(wc)
    {
        water=true;
    }
}

void BucketComponent::dropBucket(WoodComponent* wc)
{
    if(wc)
    {
        if(water)
        {
            wc->setBurning(false);
            water = false;
        }
    }
}