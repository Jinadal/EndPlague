#pragma once
#include "RenderComponent.h"
#include <vector>

class RenderManager{
    private:
        std::vector<RenderComponent*> components;
    public:
        RenderManager(){}

        ~RenderManager(){}

      
        void updateAll();

  void removecomponent(Component* c);    
  void createComponent(GameObject *owner, RenderIrrlicht *render, char path[] );

};