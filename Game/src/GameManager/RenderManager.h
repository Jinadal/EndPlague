#pragma once
#include "RenderComponent.h"
#include "RenderIrrlicht.h"
#include <vector>

class Manager;
class RenderManager : public Manager{
    private:
        RenderManager():Manager(){}
        static RenderManager* only_instance;
        
    public:
        
        static RenderManager *getInstance(){         //Pattern Singleton
            if(only_instance == NULL)
                only_instance = new RenderManager();
            
            return only_instance;
        }

        ~RenderManager(){only_instance=NULL;}
        void updateAll();
        void createComponent(GameObject *owner, char* path);

};