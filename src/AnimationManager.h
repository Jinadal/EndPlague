#pragma once
//Headers
#include "AnimationComponent.h"
#include <vector>


class AnimationManager{
  public:
    //Constructor
    AnimationManager(){}

    void addAnimationComponent(AnimationComponent* c){
        components.push_back(c);
    }
    void update(){
        for(int i=0; i<components.size();i++){
        components[i]->update();
        }
  }
private:
  std::vector<AnimationComponent*> components;
};
