#include "RenderComponent.h"
#include "GameObject.h"

void RenderComponent::update(){
    node->setPosition(gameObject->getX(),
                        gameObject->getY(),
                        gameObject->getZ());

    node->setRotation(gameObject->getRX(), 
                        gameObject->getRY(), 
                        gameObject->getRZ());

}


void RenderComponent::setVisible(bool h){
    node->setVisible(h);
}
void RenderComponent::setTexture(char s[]){
    node->setTexture(s);
}

void RenderComponent::isMap()
{
    node->isMap();
}