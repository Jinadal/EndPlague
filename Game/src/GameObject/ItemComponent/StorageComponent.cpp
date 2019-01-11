#include "StorageComponent.h"

void StorageComponent::itemCatch(ItemComponent* item)
{
    
    if(!item) return;
        
    itemDrop();
    applyEffect(item->getType());
    std::cout<<"Kil?:";
    item->getGameObject()->setKill(true);
}

void StorageComponent::itemDrop()
{
    if(itemType!=ITEM_0)
    {
        ItemFabric* fabric = new ItemFabric();
        fabric->createItem(gameObject->getX()-3.f, gameObject->getY()-3.f, gameObject->getZ(), gameObject->getRZ(), itemType);

        this->itemType = ITEM_0;
        setDefaultValues();

        delete fabric;
    }
}

void StorageComponent::setDefaultValues()
{
    gameObject->getComponent<ShootComponent>()->setCadencia(1);
    gameObject->getComponent<ShootComponent>()->setType(PROJECTILE_1);
}

void StorageComponent::applyEffect(ItemTypes Type)
{
 itemType = Type;   
    switch (Type)
    {
        case ITEM_1:
            throwable();
            break;

        case ITEM_2:
            booster();
            break;

        case ITEM_3:
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

