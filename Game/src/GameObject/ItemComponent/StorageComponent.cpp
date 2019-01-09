#include "StorageComponent.h"

void StorageComponent::itemCatch(ItemComponent* item)
{
    
    if(!item) return;
    
    std::cout<<"ItemCatch!\n";

    if(this->itemType == 1 ||
            this->itemType == 2 ||
            this->itemType == 3  )
    {
        
        itemDrop();
        this->itemType = item->getType();
        applyEffect(item->getType());
        item->getGameObject()->setKill(true);

    }
    else
    {
        this->itemType = item->getType();
        applyEffect(item->getType());
        item->getGameObject()->setKill(true);
    }
    

}

void StorageComponent::itemDrop()
{
    ItemFabric* fabric = new ItemFabric();
    fabric->createItem(gameObject->getX()-3.f, gameObject->getY()-3.f, gameObject->getZ(), gameObject->getRZ(), this->itemType-1);

    this->itemType = 0;
    setDefaultValues();

    delete fabric;
}

void StorageComponent::setDefaultValues()
{
    gameObject->getComponent<ShootComponent>()->setCadencia(1);
    gameObject->getComponent<ShootComponent>()->setType(PROJECTILE_1);
}

void StorageComponent::applyEffect(int Type)
{
    
    switch (Type)
    {
        case ITEM_THROWABLE:
            throwable();
            break;

        case ITEM_CADENCE:
            booster();
            break;

        case ITEM_LIFE:
            melon();
            break;
    
        default:
            break;
    }
}

void StorageComponent::throwable()
{
    //you thow only once a powerful weapon

    if(gameObject->getComponent<ShootComponent>())
    {
        gameObject->getComponent<ShootComponent>()->setType(PROJECTILE_2);
    }
    

}

void StorageComponent::melon()
{
    //it gives you life
    if(gameObject->getComponent<LifeComponent>())
    {
        gameObject->getComponent<LifeComponent>()->addLife(50);
    }
    
}

void StorageComponent::booster()
{
    //makes you shoot faster
    if(gameObject->getComponent<ShootComponent>())
    {
        gameObject->getComponent<ShootComponent>()->setCadencia(0.1);
    }
    
}

