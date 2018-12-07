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
enum Type {
    ITEM_THROWABLE,
    ITEM_LIFE,
    ITEM_CADENCE
};