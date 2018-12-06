#include "Component.h"

class GameObject;
class ItemComponent : public Component{
    private:
        float cadencia;
    public:
        //CONSTRUCTOR
        ItemComponent(GameObject* g, Manager* m, float cadencia) :Component(g, m){
            this->cadencia = cadencia;
        }

        //DESTRUCTOR
        ~ItemComponent(){}


};