
#include "MeshNode.h"
#include <iostream>


//Creation of a mesh node, recives the facade an the path of the mesh
MeshNode::MeshNode(RenderIrrlicht* r,char s[]){
    render = r;//Assing the facade
    mesh = render->getSMgr()->getMesh(s); //Gets a mesh

    if (!mesh)
    {
        render->getDevice()->drop();
        return;
    }
    node = render->getSMgr()->addAnimatedMeshSceneNode(mesh);//Adds the mesh to the node
    node->setMaterialFlag(video::EMF_LIGHTING, false);//Set light
    //node->setMD2Animation(scene::EMAT_STAND);//??
}

//Changes the mesh of the node to de path
void MeshNode::setMesh(char s[]){
    mesh = render->getSMgr()->getMesh(s);//Gets a new mesh

    if (!mesh)
    {
        return;
    }
    node->setMesh(mesh);//sets the mesh on the node
}

//Changes the position nsertof the node
void MeshNode::setPosition(float x, float y, float z){
    core::vector3df nodePosition = node->getPosition();
    nodePosition.Y = y;
    nodePosition.X = x;
    nodePosition.Z = z;
    node->setPosition(nodePosition);
}
//Changes the rotation of the node only in the z axis
void MeshNode::setRotation(float x, float y, float z){
    node->setRotation(core::vector3df(x, y, z));
}

//Chages the visibility of the node to b
void MeshNode::setVisible(bool b){
    node->setVisible(b);
}

//Changes the texture of the node to the new path
void MeshNode::setTexture(char s[]){
    node->setMaterialTexture( 0, render->getDriver()->getTexture(s) );
}