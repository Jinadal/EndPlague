#pragma once
#include "Manager.h"

class CameraManager : public Manager{
    private:
        CameraManager():Manager(){}
        static CameraManager* only_instance;
    public:
        ~CameraManager(){only_instance = NULL;}
        static CameraManager* getInstance(){
            if(only_instance == NULL)
                only_instance = new CameraManager();
            
            return only_instance;
        }

        void createComponent(GameObject* go);
        void updateAll(float dt);
};