#include <irrlicht.h>

class NodeFacade{
    private:
        scene::ISceneNode * node;
        RenderFacade* facade;

    public:
        NodeFacade(RenderFacade* f){
            facade = f;
            node = facade->getSceneManager()->addSphereSceneNode();
        }
        
        ~NodeFacade(){}

        int setPosition();
        int setRotation();
        int setTexture();
}