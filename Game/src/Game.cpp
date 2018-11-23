#include <iostream>
#include "GameFacade/MeshNode.h"
#include "GameObject/Gameobject.h"

//Temporal
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

//class MeshNode;
int main(int argc, char const *argv[])
{
    RenderIrrlicht* render = new RenderIrrlicht();
    RenderManager* rendermanager = new RenderManager();
    

    MeshNode* map = new MeshNode(render, "res/Map.obj"); 
    
    
    int i=0;
    while(render->run())
    {
        
        render->drawAll();
        i++;
    }

    render->drop();

    return 0;
}
