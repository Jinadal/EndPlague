#pragma once
#include "Manager.h"

class GameObject;
class GPS;
class IAManager : public Manager{
    private:
        IAManager():Manager(){init();};
        GPS* gps;
    public:
        ~IAManager(){clear();}
        static IAManager* getInstance(){
            static IAManager only_instance;
            return &only_instance;
        }

        void init();
        void clear();
        void createComponent(GameObject* owner);
        void updateAll(float dt);
        GPS* getGPS(){return gps;}
};