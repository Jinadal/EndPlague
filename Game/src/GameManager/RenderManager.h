#pragma once
#include "RenderComponent.h"
#include <vector>

class Manager;
class RenderManager : public Manager{
    private:
        RenderManager():Manager(){}
        static RenderManager* only_instance;
        
    public:
        ~RenderManager(){only_instance=NULL;}
        static RenderManager *getInstance(){
            if(!only_instance)
                only_instance = new RenderManager();
            
            return only_instance;
        }

        
        void updateAll(float dt);
        void createComponent(GameObject *owner, char* path);

};