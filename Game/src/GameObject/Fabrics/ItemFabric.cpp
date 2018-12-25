#include "ItemFabric.h"

GameObject* ItemFabric::createItem(float x, float y, float z, float rz, int type)
{
    GameObject* r =  gameresource->createGameObject(x, y, z, rz);
    rendermanager->createComponent(r, item_types[type].mesh);
    r->getComponent<RenderComponent>()->setTexture(item_types[type].texture);

    bphysicmanager->createComponent(r, .5f, .5f, .5, 10.f, 1);
    //bphysicmanager->getComponent<BPhysicComponent>()->applyForce(10.f);

    itemmanager->createComponent(r, type);

    return r;
}

