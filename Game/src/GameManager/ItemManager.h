#pragma once
#include "ItemFabric.h"
#include "Manager.h"

class GameObject;
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
        void createComponent(GameObject *owner, ItemTypes type);
        void updateAll(float dt);

};