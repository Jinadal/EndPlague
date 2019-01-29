#pragma once
#include "Manager.h"

class GameObject;
class StorageManager : public Manager{
    private:
        StorageManager():Manager(){};
        static StorageManager* only_instance;

    public:

        static StorageManager *getInstance(){
            if(only_instance == NULL)
                only_instance = new StorageManager();
            
            return only_instance;
        }

        virtual ~StorageManager() {only_instance = NULL;};
        void createComponent(GameObject *owner);
        
        void updateAll(float dt);

};