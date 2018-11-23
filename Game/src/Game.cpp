#include <iostream>
#include "RenderManager.h"
#include "RenderComponent.h"
#include "GameObject.h"


//class MeshNode;
int main(int argc, char const *argv[])
{
    RenderIrrlicht* render = new RenderIrrlicht();
    RenderManager* rendermanager = new RenderManager();
    


    GameObject* map = new GameObject(0, 0, 0, 0);//Creates a new GO on x, y, z, rz
    RenderComponent* rc = new RenderComponent(map, render, "res/Map.obj");//Creates a render Component

    rendermanager->addComponent(rc);
    map->addComponent(rc);


    GameObject* box = new GameObject(10000, 10000, 10000, 0);//Creates a new GO on x, y, z, rz
    RenderComponent* rb = new RenderComponent(box, render, "res/Block.obj");//Creates a render Component

    rendermanager->addComponent(rb);
    box->addComponent(rb);
    


    while(render->run())
    {

        rendermanager->updateAll();
        render->drawAll();

    }


    render->drop();

    return 0;
}
