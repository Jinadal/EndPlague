#pragma once
#include "Manager.h"

class CameraManager : public Manager{
    private:
        CameraManager():Manager(){}
        
    public:
        ~CameraManager(){}
        static CameraManager* getInstance(){
            static CameraManager only_instance;
            return &only_instance;
        }

        void createComponent(GameObject* go);
        void updateAll(float dt);
};