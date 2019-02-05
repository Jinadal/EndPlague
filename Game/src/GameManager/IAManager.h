#pragma once
#include "Manager.h"

class GameObject;
class GPS;
class IAManager : public Manager{
    private:
        IAManager();
        static IAManager *only_instance;
        GameObject* player;
        GPS* gps;
       
    public:
        virtual ~IAManager(){only_instance=NULL; }
        //Constructor Singletone
        static IAManager *getInstance(){
            if(only_instance == NULL){only_instance = new IAManager();}
            return only_instance;
        }
        void setPlayer(GameObject* player){this->player = player;}
        void createComponent(GameObject* owner);
        void updateAll(float dt);
        GameObject* getPlayer(){return player;}
        GPS* getGPS(){return gps;}
};