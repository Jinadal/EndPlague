#pragma once
#include "Component.h"

class GameObject;
class ItemComponent : public Component{
    private:
        int Type;

        

    public:
        //CONSTRUCTOR
        ItemComponent(GameObject* g, Manager* m, int Type) :Component(g, m){
            this->Type = Type;
        }

        //DESTRUCTOR
        ~ItemComponent(){}

        int getType(){
            return Type;
        }


};

enum ItemType {
    ITEM_NONE, //0
    ITEM_THROWABLE, //1
    ITEM_LIFE, //2
    ITEM_CADENCE //3
};