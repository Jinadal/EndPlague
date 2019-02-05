#include "Component.h"
#include "ItemFabric.h"

#define P_ITEM1 10.f
#define P_ITEM2 10.f
#define P_ITEM3 10.f


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