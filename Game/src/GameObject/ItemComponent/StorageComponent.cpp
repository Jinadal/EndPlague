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
            crossbow();
            break;

        case ITEM_3:
            potion();
            break;
        
        case ITEM_4:
            sword();
            break;

        case ITEM_5:
            peak();
            break;

        case ITEM_6:
            machete();
            break;

        case ITEM_7:
            shield();
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
    }
    
}

void StorageComponent::machete()
{
    //Ataque básico cuerpo a cuerpo
}

void StorageComponent::sword()
{
    //++ataque cuerpo a cuerpo
}

void StorageComponent::peak()
{
    //+ataque cuerpo a cuerpo
}

void StorageComponent::shield()
{
    //+% de vida no recuperable
}
