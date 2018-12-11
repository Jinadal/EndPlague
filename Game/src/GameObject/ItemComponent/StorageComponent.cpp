#include "StorageComponent.h"
#include <iostream>


void StorageComponent::itemCatch(ItemComponent* item)
{
    if(!item)
        return;

    
    if(this->item)
    {
        if(this->item->getType() != item->getType())
        {
            itemDrop();
            itemCatch(item);
        }

    }
    else
    {
        this->item = item;
        applyEffect(item->getType());
        item->getGameObject()->setKill(true);
        std::cout<<"He cogido el item\n";
    }
    

}

void StorageComponent::itemDrop()
{
    this->item = NULL;
    setDefaultValues();
    std::cout<<"He tirado el objeto que tenia\n";
}

void StorageComponent::setDefaultValues()
{
    gameObject->getComponent<ShootComponent>()->setCadencia(1);
    gameObject->getComponent<ShootComponent>()->setProjectileKind(1);
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
        std::cout<<"I'm a throwable\n";
        gameObject->getComponent<ShootComponent>()->setProjectileKind(2);
    }
    

}

void StorageComponent::melon()
{
    //it gives you life
    if(gameObject->getComponent<LifeComponent>())
    {
        std::cout<<"I give you life\n";
        gameObject->getComponent<LifeComponent>()->addLife(50);
    }
    
}

void StorageComponent::booster()
{
    //makes you shoot faster
    if(gameObject->getComponent<ShootComponent>())
    {
        std::cout<<"I modify your cadence\n";
        gameObject->getComponent<ShootComponent>()->setCadencia(-0.8);
    }
    
}

