#pragma once

#include <vector>
#include <memory>
#include "Component.h"

class Component;

class GameObject{
    private:
        int x, y, z, rz;
        std::vector<Component*> components;

    public:
    GameObject(int x, int y, int z, int rz);

    ~GameObject()=default;

   

    int getX(){return x;}
    int getY(){return y;}
    int getZ(){return z;}
    int getRZ(){return rz;}

    int setX(int x){this->x = x;}
    int setY(int y){this->y = y;}
    int setZ(int z){this->z = z;}
    int setRZ(int rz){this->rz = rz;}

	


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