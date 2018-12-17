#pragma once
#include "CameraComponent.h"

class Manager;
class CameraManager : public Manager{
    private:
        CameraManager():Manager(){}
        static CameraManager* only_instance;
    public:
        static CameraManager* getInstance(){
            if(only_instance == NULL)
                only_instance = new CameraManager();
            
            return only_instance;
        }

        ~CameraManager(){
            only_instance = NULL;
        }

        void createComponent(GameObject* go);
        void updateAll(float dt);
};