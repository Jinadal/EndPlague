#include "Component.h"
#define FIRE_DAMMAGE 10.f
#define BUCKETS_NEDED 10

class WoodComponent:public Component
{
    private:
        float life;
        bool burning;
        int buckets;
    public:
        WoodComponent(GameObject* owner, Manager* manager, float life):Component(owner, manager)
        {
            this->life = life;
            burning = false;
            buckets=0;
        }
        ~WoodComponent(){}


        void setBurning(bool b);
        bool getBurning(){return burning;}
        void update(float dt);
        void addBucket();
};