#include "../../GameFacade/MeshNode.h"

class RenderComponent : Component{
    private:
        MeshNode* node;
        RenderIrrlitch* render;
    public:
        RenderComponent(GameObject g, RenderIrrlitch* r, char s[]) : Component(g){
            render = r;
            node = new MeshNode(r, s);
        }

        ~RenderComponent(){}

        void update();
        void setVisible(bool h);
        void setTexture(char s[]);
        void setMesh(char s[]);
};