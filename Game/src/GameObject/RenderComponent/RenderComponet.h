#include "MeshNode.h"

class RenderComponent : Component{
    private:
        MeshNode* node;
        RenderIrrlitch* render;
    public:
        //Creates the componet, adds the parent g, and creates a node on r, with s mesh path
        RenderComponent(GameObject g, RenderIrrlitch* r, char s[]) : Component(g);

        //Destructor
        ~RenderComponent(){}

        //Updates the position and the scale of the mesh
        void update();

        //Sets the visibility to h
        void setVisible(bool h);

        //Sets the texture
        void setTexture(char s[]);

        //Sets the mesh
        void setMesh(char s[]);
};