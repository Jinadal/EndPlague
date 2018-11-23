#include "RenderComponent.h"

void RenderComponent::update(){
            node->setPosition(parent->getX(),
                                parent->getY(),
                                parent->getZ(),);
        
            node->setRotation(parent->getR());
        }

void RenderComponent::hide(bool h){
    node->hide(h);
}
void RenderComponent::setTexture(char s[]){
    node->setTexture(s);
}
void RenderComponent::setMesh(char s[]){
    node->setMesh(s);
}