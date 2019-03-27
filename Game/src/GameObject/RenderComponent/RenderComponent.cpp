#include "RenderComponent.h"
#include "GameObject.h"
#include <cmath>
void RenderComponent::update(float dt){

    float sz = 0.f;
    if(leviosa){
        this->time += dt;
        sz = - 0.6 + 0.6 * sin(1.8 * time); 
    }

    node->setPosition(gameObject->getX(),
                        gameObject->getY(),
                        gameObject->getZ() + sz);

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