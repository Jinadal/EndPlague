#pragma once
//Headers
#include "InputComponent.h"
#include <vector>


class InputManager{
  public:
    //Constructor
    InputManager(){}

    void addInputComponent(InputComponent* c){
        components.push_back(c);
    }
    void update(){
        for(int i=0; i<components.size();i++){
        components[i]->update();
        }
  }
private:
  std::vector<InputComponent*> components;
};
