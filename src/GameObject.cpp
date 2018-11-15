
#include "GameObject.h"
#include "Component.h"


//Constructor
GameObject::GameObject(int x, int y){
    this->x = x;
    this->y = y;
}

//Add component
void GameObject::addComponent(Component* c){
    this->components.push_back(c);
}

//Get Component
template<typename T>
T* GameObject::getComponent() {
    for(int i=0; i<components.size(); i++){
        if(T* c = static_cast<T*>(components[i])){
            return c;
        }
    }     
    return nullptr;
}

