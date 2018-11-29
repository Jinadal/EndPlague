#pragma once
#include "RenderComponent.h"
#include <vector>

class RenderManager{
    private:
        std::vector<RenderComponent*> components;
        static RenderManager* only_instance;
        RenderManager(){}
    public:
        ~RenderManager(){}
        
        static RenderManager *getInstance(){         //Pattern Singleton
            if(only_instance == NULL)
                only_instance = new RenderManager();
            
            return only_instance;
        }

      
        void updateAll();

  void removecomponent(Component* c);    
  void createComponent(GameObject *owner, RenderIrrlicht *render, char path[] );

};