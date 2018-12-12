#pragma once
#include "Component.h"
#include "GameObject.h"
#include "ItemComponent.h"
#include "ShootComponent.h"
#include "LifeComponent.h"




class StorageComponent : public Component{
    private:
        ItemComponent*  item;
        float initialCadence;
        int initialType;


    public:
        StorageComponent(GameObject* g, Manager* m):Component(g, m){};
        ~StorageComponent(){};

        //Stores the item if possible
        void itemCatch(ItemComponent* item);
        //Drops the actual item
        void itemDrop();
        //Applies the effect of the item 
        void applyEffect(int Type);

        void setDefaultValues();

        void booster();
        void melon();
        void throwable();
};