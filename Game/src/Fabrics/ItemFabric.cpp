#include "ItemFabric.h"

#include "RenderManager.h"
#include "BPhysicManager.h"
#include "ItemManager.h"
#include "GameResource.h"

GameObject* ItemFabric::createItem(float x, float y, float z, float rz, ItemTypes type)
{
    GameObject* r =  GameResource::getInstance()->createGameObject(x, y, z, rz);
    RenderManager::getInstance()->createComponent(r, item_types[type].mesh);
    r->getComponent<RenderComponent>()->setTexture(item_types[type].texture);

    BPhysicManager::getInstance()->createComponent(r, .5f, .5f, .5, 10.f, 1);
    //bphysicmanager->getComponent<BPhysicComponent>()->applyForce(10.f);

    ItemManager::getInstance()->createComponent(r, type);

    return r;
}

