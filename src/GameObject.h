#pragma once
#include "Component.h"
#include <vector>

class Component;

class GameObject
{
public:
  int velocity=0;
  int x=0, y=0;

  GameObject(){}

  GameObject(int x, int y, int velocity){
    this->x = x;
    this->y = y;
    this->velocity = velocity;
  }

  void addComponent(Component* c){
    components.push_back(c);
  }
private:
  std::vector<Component*> components;
};