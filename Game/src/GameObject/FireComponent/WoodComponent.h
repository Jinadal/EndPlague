#include "Component.h"
#define FIRE_DAMMAGE 10.f


class WoodComponent:public Component
{
    private:
        float life;
        bool burning;
    
    public:
        WoodComponent(GameObject* owner, Manager* manager, float life):Component(owner, manager)
        {
            this->life = life;
            burning = false;
        }
        ~WoodComponent(){}


        void setBurning(bool b);
        bool getBurning(){return burning;}
        void update(float dt);
};