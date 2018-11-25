#include <iostream>
#include "RenderManager.h"
#include "RenderComponent.h"
#include "GameObject.h"
#include "CollisionManager.h"
#include "CollisionComponent.h"


int main()
{
    RenderIrrlicht* render = new RenderIrrlicht();
    RenderManager* rendermanager = new RenderManager();

    GameObject* map = new GameObject(0, 0, 0, 0);//Creates a new GO on x, y, z, rz
    RenderComponent* rc = new RenderComponent(map, render, "res/Map.obj");//Creates a render Component

    rendermanager->addComponent(rc);
    map->addComponent(rc);

    float i = 0;
    float d = .001;
    while(render->run())
    {
        map->setZ(i);
        rendermanager->updateAll();
        render->drawAll();
        i += d;
    }

    render->drop();


    return 0;
}
