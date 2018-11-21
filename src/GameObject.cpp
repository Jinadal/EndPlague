
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


//void GameObject::kill()
//{
//    std::vector<Component *>::iterator iter;
//
//	for(iter=components.begin(); iter!=components.end(); ++iter)
//
//	{
//
//		(*iter)->kill();
//
//	}
//
//	components.clear();
//}