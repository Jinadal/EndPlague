#pragma once
#include "Manager.h"

class GameObject;
class BucketManager : public Manager{
    private:
        BucketManager():Manager(){}

        static BucketManager* only_instance;
    
    public:
        ~BucketManager(){only_instance = NULL;}
        static BucketManager* getInstance()
        {
            if(!only_instance)only_instance=new BucketManager();

            return only_instance;
        }

        void createComponent(GameObject* owner);
        void updateAll(float dt){};
};