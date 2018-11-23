#pragma once
#include "Component.h"
#include <vector>

class GameObject
{
	private:
    int x=0, y=0;
    std::vector<Component*> components;

  public:
    GameObject(int x_, int y_);


    ~GameObject()=default;

   

    int getX(){return x;}
    int getY(){return y;}

	


	//Add component
    void addComponent(Component* c);



	template<typename T>
T* getComponent() {
    for(int i=0; i<components.size(); i++){
        if(T* c = dynamic_cast<T*>(components[i])){
            return c;
        }
    }     
    return nullptr;
}

};