#include "Component.h"
#include "ItemFabric.h"

const int P_POTION      = 30;
const int P_AXE         = 35;
const int P_PEAK        = 40;
const int P_CROSSBOW    = 50;
const int P_SHIELD      = 80;



struct Items
{
    float prob;
    ItemTypes item;
};


class DropperComponent : public Component
{
    public:
        DropperComponent(GameObject* owner, Manager* manager) : Component(owner, manager){};
        ~DropperComponent();
        void dropItem();
};