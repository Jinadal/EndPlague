#include "StorageComponent.h"
#include "GameObject.h"
#include "ItemComponent.h"
#include "ShootComponent.h"
#include "LifeComponent.h"

void StorageComponent::itemCatch(ItemComponent* item)
{
    
    if(!item) return;
        
    itemDrop();
    applyEffect(item->getType());
    itemType = item->getType();
    item->getGameObject()->setKill(true);
}

void StorageComponent::itemDrop()
{
    if(itemType == EMPTY || itemType == POTION || itemType == SHIELD)
        return;

    ItemFabric* fabric = new ItemFabric();
    fabric->createItem(gameObject->getX()-3.f, gameObject->getY()-3.f, gameObject->getZ(), gameObject->getRZ(), itemType);

    this->itemType = EMPTY;

    delete fabric;
}

void StorageComponent::applyEffect(ItemTypes Type)
{ 
    switch (Type)
    {
        case CROSSBOW:
            crossbow();
            break;

        case AXE:
            axe();
            break;

        case POTION:
            potion();
            break;

        case PEAK:
            peak();
            break;

        case SHIELD:
            shield();
            break;
    
        default:
            break;
    }
}


void StorageComponent::potion()
{
    //it gives you life
    if(gameObject->getComponent<LifeComponent>())
    {
        gameObject->getComponent<LifeComponent>()->addLife(50);
    }
    
}

void StorageComponent::crossbow()
{
    //makes you shoot faster
    if(gameObject->getComponent<ShootComponent>())
    {
        gameObject->getComponent<ShootComponent>()->setCadencia(0.1);
        gameObject->getComponent<ShootComponent>()->setType(PARROW);
    }
    
}


void StorageComponent::peak()
{
    //makes you shoot faster
    if(gameObject->getComponent<ShootComponent>())
    {
        gameObject->getComponent<ShootComponent>()->setCadencia(0.5);
        gameObject->getComponent<ShootComponent>()->setType(PPEAK);
    }
}

void StorageComponent::shield()
{
    //it gives you life shield
    if(gameObject->getComponent<LifeComponent>())
    {
        gameObject->getComponent<LifeComponent>()->setShield(100);
    }
    
}

void StorageComponent::axe()
{
    //makes you shoot faster
    if(gameObject->getComponent<ShootComponent>())
    {
        gameObject->getComponent<ShootComponent>()->setCadencia(0.8);
        gameObject->getComponent<ShootComponent>()->setType(PAXE);
    }
}