#pragma once

#include <vector>
#include <memory>
#include "Component.h"

class Component;

class GameObject{
    private:
        float x, y, z, rz;
        std::vector<Component*> components;

    public:
    GameObject(float x, float y, float z, float rz);

    ~GameObject()=default;

   

    float getX(){return x;}
    float getY(){return y;}
    float getZ(){return z;}
    float getRZ(){return rz;}

    void setX(float x){this->x = x;}
    void setY(float y){this->y = y;}
    void setZ(float z){this->z = z;}
    void setRZ(float rz){this->rz = rz;}

	


	//Add component
    void addComponent(Component* c);



	template<typename T>
    T* getComponent() {
        for(auto& c : components){
            if(T* cm = dynamic_cast<T*>(c)){
                return cm;
            }
        }     
        return nullptr;
    }

};