#include "GameObject.h"
#include "Component.h"

//Constructor
GameObject::GameObject(float x, float y, float z, float rz){
    this->x     = x;
    this->y     = y;
    this->z     = z;
    this->rx    = 0;
    this->ry    = 0;
    this->rz    = rz;
}

//Add component
void GameObject::addComponent(Component* c){
    components.push_back(c);
}

void GameObject::kill(){}