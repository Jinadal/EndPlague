#pragma once
#include "Component.h"
#include <vector>

class Component;

class GameObject
{
public:
  
  GameObject(){}

  GameObject(int cx, int cy){
    this->x = cx;
    this->y = cy;

  }
  //Setter&Getter
  //Get Component
  template<typename T>
  T getComponent() {
      for (auto comp: components) {
          if (T cmp = dynamic_cast<T>(comp)) {
              return cmp;
          }
      }
      return nullptr;
  }  

  //Methods
  void addComponent(Component* c){
    components.push_back(c);
  }
private:
  int x,y; //Coordenades
  std::vector<Component*> components;
};