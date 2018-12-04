#include "Component.h"

class GameObject;
class ItemComponent : public Component{
    private:
        int type;
    public:
        //CONSTRUCTOR
        ItemComponent(GameObject* g, Manager* m, int type):Component(g, m){
            this->type = type;
        }

        //DESTRUCTOR
        virtual ~ItemComponent(){}

        //Stores the item if possible
        bool itemCatch();
        //Drops the actual item
        bool itemDrop();


        //SETTERS AND GETTERS
        int getType(){return type;}
        void setType(int t){type = t;}
};