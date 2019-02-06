#pragma once
#include "Manager.h"

class GameObject;
class StorageManager : public Manager{
    private:
        StorageManager():Manager(){};
        static StorageManager* only_instance;

    public:
        ~StorageManager() {only_instance = nullptr;};
        static StorageManager *getInstance(){
            if(!only_instance)
                only_instance = new StorageManager();
            
            return only_instance;
        }

        void createComponent(GameObject *owner);
        
        void updateAll(float dt);

};