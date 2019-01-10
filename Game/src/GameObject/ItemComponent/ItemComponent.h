#pragma once
#include "Component.h"
#include "ItemFabric.h"

class GameObject;
class ItemComponent : public Component{
    private:
        ItemTypes Type;

    public:
        //CONSTRUCTOR
        ItemComponent(GameObject* g, Manager* m, ItemTypes Type) :Component(g, m){
            this->Type = Type;
        }

        //DESTRUCTOR
        ~ItemComponent(){}

        ItemTypes getType(){
            return Type;
        }


};

enum ItemType {
    ITEM_NONE, //0
    ITEM_THROWABLE, //1
    ITEM_LIFE, //2
    ITEM_CADENCE //3
};