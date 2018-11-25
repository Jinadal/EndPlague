#pragma once
#include "MeshNode.h"
#include <iostream>



MeshNode::MeshNode(RenderIrrlicht* r,char s[]){
    render = r;
    mesh = render->getSMgr()->getMesh(s);

    if (!mesh)
    {
        render->getDevice()->drop();
        return;
    }
    
    node = render->getSMgr()->addAnimatedMeshSceneNode(mesh);
    node->setMaterialFlag(video::EMF_LIGHTING, false);

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
void MeshNode::setPosition(float x, float y, float z){
    core::vector3df nodePosition = node->getPosition();
    nodePosition.Y = y;
    nodePosition.X = x;
    nodePosition.Z = z;
    node->setPosition(nodePosition);
}
//Changes the rotation of the node only in the z axis
void MeshNode::setRotation(float r){
    node->setRotation(core::vector3df(0, 0, r));
}

//Chages the visibility of the node to b
void MeshNode::setVisible(bool b){
    node->setVisible(b);
}

//Changes the texture of the node to the new path
void MeshNode::setTexture(char s[]){

}