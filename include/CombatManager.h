#pragma once
//Headers
#include "CombatComponent.h"
#include <vector>


class CombatManager{
  public:
    //Constructor
    CombatManager(){}

    void addCombatComponent(CombatComponent* c){
        components.push_back(c);
    }
    void update(){
        for(int i=0; i<components.size();i++){
        components[i]->update();
        }
  }
private:
  std::vector<CombatComponent*> components;
};