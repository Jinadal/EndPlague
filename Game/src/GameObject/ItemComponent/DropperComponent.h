#include "Component.h"
#include "ItemFabric.h"

#define P_ITEM1 10
#define P_ITEM2 10
#define P_ITEM3 10
#define P_ITEM4 10
#define P_ITEM5 10
#define P_ITEM6 10
#define P_ITEM7 10



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