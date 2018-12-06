#pragma once
#include "MovementComponent.h"
#include <vector>

class Manager;
class MovementManager : public Manager{
    private:
        MovementManager():Manager(){}
        static MovementManager *only_instance;

    public:
        static MovementManager* getInstance(){
            if(only_instance == NULL)
                only_instance = new MovementManager();
            
            return only_instance;
        } 

        virtual ~MovementManager(){only_instance=NULL;}

        void addComponent(MovementComponent* rc);
        void updateAll(float dt);   
        void createComponent(GameObject *owner);
};