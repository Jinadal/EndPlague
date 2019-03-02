#pragma once
#include "MeshNode.h"
#include "Component.h"
#include "RenderIrrlicht.h"

class GameObject;
class RenderComponent : public Component{
    private:
        MeshNode* node;
    public:
        //Creates the componet, adds the parent g, and creates a node on r, with s mesh path
        RenderComponent(GameObject* g, Manager* m, char* s) : Component(g, m){
            node = RenderIrrlicht::getInstance()->createMesh(s);
        }
        //Destructor
        virtual ~RenderComponent(){delete node;}

        //Updates the position and the scale of the mesh
        void update();

        //Sets the visibility to h
        void setVisible(bool h);

        //Sets the texture
        void setTexture(char s[]);

        void isMap();
};