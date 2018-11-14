#pragma once
//Headers
#include "SpawnComponent.h"
#include <vector>


class SpawnManager{
  public:
    //Constructor
    SpawnManager(){}

    void addSpawnComponent(SpawnComponent* c){
        components.push_back(c);
    }
    void update(){
        for(int i=0; i<components.size();i++){
        components[i]->update();
        }
  }
private:
  std::vector<SpawnComponent*> components;
};
