#include "MeshNode.h"



MeshNode::MeshNode(RenderIrrlicht* r,char s[]){
    render = r;
    mesh = render->getSMgr()->getMesh(s);

    if (!mesh)
    {
        render->getDevice()->drop();
        return;
    }

    node = render->getSMgr()->addAnimatedMeshSceneNode(mesh);
}

//Changes the mesh of the node to de path
void MeshNode::setMesh(char s[]){
    mesh = render->getSMgr()->getMesh(s);

    if (!mesh)
    {
        return;
    }

    node->setMesh(mesh);
}

//Changes the position of the node
void MeshNode::setPosition(int x, int y, int z){
    node->setPosition(core::vector3df(x, y, z));
}
//Changes the rotation of the node only in the z axis
void MeshNode::setRotation(int r){
    node->setPosition(core::vector3df(0, 0, r));
}

//Chages the visibility of the node to b
void MeshNode::setVisible(bool b){
    node->setVisible(b);
}

//Changes the texture of the node to the new path
void MeshNode::setTexture(char s[]){

}