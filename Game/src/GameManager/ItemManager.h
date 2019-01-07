#pragma once
#include "GameObject.h"

class GameObject;
class Manager;

class ItemManager : public Manager{
    private:
        ItemManager():Manager(){}
        static ItemManager* only_instance;
    
    public:
        //CONSTRUCTOR
        static ItemManager *getInstance(){
            if (only_instance == NULL)
                only_instance = new ItemManager();

            return only_instance;
        }

        //DESTRUCTOR
        virtual ~ItemManager() {only_instance = NULL;};
        void createComponent(GameObject *owner, float type);
        void updateAll(float dt);

};