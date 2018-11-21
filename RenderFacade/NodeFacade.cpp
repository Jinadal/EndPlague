#include <NodeFacade.h>

int MeshFacade::setPosition(int x, int y, int z){
    node->setPosition(core::vector3df(x,y,z));
}

int MeshFacade::setRotation(int x, int y, int z){
    node->setPosition(core::vector3df(x,y,z));
}

int MeshFacade::setMaterialTexture(String s){
    node->setMaterialTexture(0, facade->getDriver()->getTexture(s))
}
