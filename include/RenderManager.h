#pragma once
//Headers
#include "RenderComponent.h"
#include <vector>


class RenderManager{
  public:
    //Constructor
    RenderManager(){}

    void addRenderComponent(RenderComponent* c){
        components.push_back(c);
    }
    void update(){
        for(int i=0; i<components.size();i++){
        components[i]->update();
        }
  }
private:
  std::vector<RenderComponent*> components;
};