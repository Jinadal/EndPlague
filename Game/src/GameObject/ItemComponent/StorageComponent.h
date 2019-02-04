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
        
        //DISTANCE WEAPONS
            //Attack with crossbow
            void crossbow(); //YES
            //Attacks throwing axes
            void throwable(); //YES
        //MELEE WEAPONS
            //machete
            void machete(); //YES
            //sword
            void sword(); //YES
            //peak
            void peak(); //yes
        //USABLE ITEMS
            //Potion
            void potion(); //YES
            //Shield
            void shield();
};