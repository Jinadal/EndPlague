#include "GameObject.h"

//Constructor
GameObject::GameObject(int x, int y, int z, int rz){
    this->x     = x;
    this->y     = y;
    this->z     = z;
    this->rz    = rz;
}
//Init
void GameObject::init() {
    //Initilize all components
    for (auto& comp : components)
		comp.get()->init();
}

//Close
void GameObject::close(){
    for (auto comp : components)
        comp.get()->close();
}

//Add component
void GameObject::addComponent(Component* c){
    components.push_back(c);
}

//Get Component
template<typename T>
T* GameObject::getComponent() {
    for(auto& cm : components){
        
        if(T* c = static_cast<T*>(cm){
            return c;
        }
    }
    return nullptr;
}   