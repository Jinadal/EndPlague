#include <iostream>
#include "RenderManager.h"
#include "Gameobject.h"

//class MeshNode;
int main(int argc, char const *argv[])
{
    RenderIrrlicht* render = new RenderIrrlicht();
    RenderManager* rendermanager = new RenderManager();
    


    GameObject* map = new Gameobject(0, 0, 0, 0);//Creates a new GO on x, y, z, rz
    RenderComponent* rc = new RenderComponent(render, "res/Map.obj");//Creates a render Component

    rendermanager->addComponent(rc);
    map->addComponent(rc);


    while(render->run())
    {
        
        render->drawAll();

    }


    render->drop();

    return 0;
}
