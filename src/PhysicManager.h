#pragma once
//Headers
#include "PhysicComponent.h"
#include <vector>


class PhysicManager{
  public:
    //Constructor
    PhysicManager(){}

    void addPhysicComponent(PhysicComponent* c){
        components.push_back(c);
    }
    void update(){
        for(int i=0; i<components.size();i++){
        components[i]->update();
        }
  }
private:
  std::vector<PhysicComponent*> components;
};
