#include "RenderComponent.h"


RenderComponent::RenderComponent(GameObject* g, RenderIrrlicht* r, char s[]) : Component(g){
    render = r;
    node = new MeshNode(r, s);
}

void RenderComponent::update(){
            node->setPosition(gameObject->getX(),
                                gameObject->getY(),
                                gameObject->getZ());
        
            node->setRotation(gameObject->getRZ());
        }

void RenderComponent::setVisible(bool h){
    node->setVisible(h);
}
void RenderComponent::setTexture(char s[]){
    node->setTexture(s);
}
void RenderComponent::setMesh(char s[]){
    node->setMesh(s);
}