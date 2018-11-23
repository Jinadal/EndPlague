#include "GameObject.h"
#include "Component.h"



GameObject::GameObject(int x, int y)
{
    this->x = x;
    this->y = y;
}



//Add component
void GameObject::addComponent(Component* c){
    this->components.push_back(c);
}