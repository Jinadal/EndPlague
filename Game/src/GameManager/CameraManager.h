#pragma once
#include "Manager.h"

class CameraManager : public Manager{
    private:
        CameraManager():Manager(){}
        static CameraManager* only_instance;
    public:
        ~CameraManager(){only_instance = nullptr;}
        static CameraManager* getInstance(){
            if(!only_instance)
                only_instance = new CameraManager();
            
            return only_instance;
        }

        void createComponent(GameObject* go);
        void updateAll(float dt);
};