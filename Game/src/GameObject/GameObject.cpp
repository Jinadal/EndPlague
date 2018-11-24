#include "GameObject.h"
#include "Component.h"

//Constructor
GameObject::GameObject(int x, int y, int z, int rz){
    this->x     = x;
    this->y     = y;
    this->z     = z;
    this->rz    = rz;
}

//Add component
void GameObject::addComponent(Component* c){
    components.push_back(c);
}