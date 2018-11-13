#pragma once
//Headers
#include "IAComponent.h"
#include <vector>


class IAManager{
  public:
    //Constructor
    IAManager(){}

    void addIAComponent(IAComponent* c){
        components.push_back(c);
    }
    void update(){
        for(int i=0; i<components.size();i++){
        components[i]->update();
        }
  }
private:
  std::vector<IAComponent*> components;
};