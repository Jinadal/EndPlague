#include "ItemFabric.h"

GameObject* ItemFabric::createItem(float x, float y, float z, float rz, int type)
{
    GameObject* r =  gameresource->createGameObject(x, y, z, rz);
    rendermanager->createComponent(r, item_types[type].mesh);
    r->getComponent<RenderComponent>()->setTexture(item_types[type].texture);

    collisionmanager->createComponent(r, 30.f, 30.f, true);

    itemmanager->createComponent(r, type);

    return r;
}

