#pragma once
//Headers
#include "CollisionComponent.h"
#include <vector>


class CollisionManager{
  public:
    //Constructor
    CollisionManager(){}

    void addCollisionComponent(CollisionComponent* c){
        components.push_back(c);
    }
    void update(){
        for(int i=0; i<components.size();i++){
        components[i]->update();
        }
  }
private:
  std::vector<CollisionComponent*> components;
};