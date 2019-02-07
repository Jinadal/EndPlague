#include "Component.h"
#include "ItemFabric.h"

#define P_POTION 30
#define P_AXE 35
#define P_PEAK 40
#define P_CROSSBOW 50
#define P_SHIELD 50



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