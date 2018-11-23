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

        ~GameObject(){}

        int getX(){return x;}
        int getY(){return y;}
        int getZ(){return z;}
        int getRZ(){return rz;}
        void setX(int x){this->x=x;}
        void setY(int y){this->y=y;}
        void setZ(int z){this->z=z;}
        void setRZ(int rz){this->rz=rz;}

        void addComponent(Component* adding);

        //Get Component
        template<typename T> T* getComponent();

        void init();

        //Close
        void close();
};