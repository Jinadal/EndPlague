#pragma once

#include <vector>
#include <memory>
#include "Component.h"

class Component;

class GameObject{
    private:
        float x, y, z, rx, ry, rz;
        std::vector<Component*> components;

    public:
    GameObject(float x, float y, float z, float rz);

    virtual ~GameObject(){}

   

    float getX(){return x;}
    float getY(){return y;}
    float getZ(){return z;}
    float getRX(){return rx;}
    float getRY(){return ry;}
    float getRZ(){return rz;}
    

    void setX(float x){this->x = x;}
    void setY(float y){this->y = y;}
    void setZ(float z){this->z = z;}
    void setRX(float rx){this->rx = rx;}
    void setRY(float ry){this->ry = ry;}
    void setRZ(float rz){this->rz = rz;}

	


	//Add component
    void addComponent(Component* c);
    void kill();


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