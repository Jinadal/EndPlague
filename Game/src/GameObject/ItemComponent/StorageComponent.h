#pragma once
#include "Component.h"
#include "GameObject.h"
#include "ItemComponent.h"



class StorageComponent : public Component{
    private:
        ItemComponent* item;


    public:
        StorageComponent(GameObject* g, Manager* m, float cadencia):Component(g, m){};
        ~StorageComponent(){};

        //Stores the item if possible
        void itemCatch(ItemComponent* item);
        //Drops the actual item
        void itemDrop();
};