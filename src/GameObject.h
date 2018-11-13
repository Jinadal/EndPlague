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

  GameObject(int x, int y){
    this->x = x;
    this->y = y;
  }

  void addComponent(Component* c){
    components.push_back(c);
  }

  //Get Component
  template<typename T>
  T* getComponent() {
      for(int i=0; i<components.size(); i++){
          if(T* c = static_cast<T*>(components[i])){
              return c;
          }
      }
      
      return nullptr;
  }   

private:
  std::vector<Component*> components;
};