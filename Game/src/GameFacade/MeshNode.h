#include "RenderIrrlicht.h"



/*
Node ony implemented with a AnimatedMesh in Irr
*/
class MeshNode{
    private:
        RenderIrrlicht* render;//Irrlich facade
        IAnimatedMesh* mesh;//Mesh of the node
        IAnimatedMeshSceneNode* node;//Node

    public:
        //Recives de render facade, and de path of the mesh
        //and creates a meshNode
        MeshNode(RenderIrrlicht* r,char s[]){
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
        void setMesh(char s[]){
            mesh = render->getSMgr()->getMesh(s);

            if (!mesh)
            {
                return;
            }

            node->setMesh(mesh);
        }

        //Changes the position of the node
        void setPosition(int x, int y, int z){
            node->setPosition(core::vector3df(x, y, z));
        }
        //Changes the rotation of the node only in the z axis
        void setRotation(int r){
            node->setPosition(core::vector3df(0, 0, r));
        }

        //Chages the visibility of the node to b
        void setVisible(bool b){
            node->setVisible(b);
        }
        
        //Changes the texture of the node to the new path
        void setTexture(char s[]){

        }

};