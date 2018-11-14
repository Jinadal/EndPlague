#pragma once
#include "Component.h"
#include <vector>

class Component;

class GameObject
{
  private:
    int x=0, y=0;
    std::vector<Component*> components;

  public:
    GameObject(int x, int y);

    ~GameObject();

    int getX(){return x;}
    int getY(){return y;}
    void setX(int x){this->x=x;}
    void serY(int y){this->y=y;}

    void addComponent(Component* c);

    template<typename T>
    T* getComponent();
};