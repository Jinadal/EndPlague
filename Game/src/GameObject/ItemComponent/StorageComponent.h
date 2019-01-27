#pragma once
#include "Component.h"
#include "ItemFabric.h"

class GameObject;
class ItemComponent;
class StorageComponent : public Component{
    private:
        ItemTypes itemType = ITEM_0;
        float initialCadence;
        ItemTypes initialType;

    public:
        StorageComponent(GameObject* g, Manager* m):Component(g, m){};
        ~StorageComponent(){};

        //Stores the item if possible
        void itemCatch(ItemComponent* item);
        //Drops the actual item
        void itemDrop();
        //Applies the effect of the item 
        void applyEffect(ItemTypes Type);

        void setDefaultValues();

        void booster();
        void melon();
        void throwable();
};