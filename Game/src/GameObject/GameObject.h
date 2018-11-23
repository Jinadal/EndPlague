#pragma once

#include <vector>
#include <memory>
#include "Component.h"

class Component;

class GameObject{
    private:
        int x, y;
        std::vector<Component*> components;

    public:
        GameObject(int x, int y){
            this->x = x;
            this->y = y;
        }

        int getX(){return x;};
        int getY(){return y;};
        void setX(int x){this->x=x;};
        void setY(int y){this->y=y;};


        void addComponent(Component* adding){
            components.push_back(adding);
        }



        //Get Component
        template<typename T>
        T* getComponent() {
            for(auto& cm : components){
                
                if(T* c = static_cast<T*>(cm){
                    return c;
                }
            }
            
            return nullptr;
        }   
};