#include "GameObject.h"
#include "Component.h"
#include <iostream>

//Constructor
GameObject::GameObject(float x, float y, float z, float rz){
    this->x     = x;
    this->y     = y;
    this->z     = z;
    this->rx    = 0;
    this->ry    = 0;
    this->rz    = rz;
    kill        = false;
}

//Destructor
GameObject::~GameObject(){
    components.clear();
}

//Add component
void GameObject::addComponent(Component* c){
    components.push_back(c);
}
void GameObject::toKill(){kill=true;}