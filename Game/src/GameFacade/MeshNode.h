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
        MeshNode(RenderIrrlicht* r,char s[]);

        //Destructor
        virtual ~MeshNode(){}
        
        //Changes the mesh of the node to de path
        void setMesh(char s[]);

        //Changes the position of the node
        void setPosition(float x, float y, float z);

        //Changes the rotation of the node only in the z axis
        void setRotation(float x, float y, float z);

        //Chages the visibility of the node to b
        void setVisible(bool b);
        
        //Changes the texture of the node to the new path
        void setTexture(char s[]);

};