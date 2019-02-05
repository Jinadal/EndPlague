#include "Component.h"
#include "ItemFabric.h"

#define P_ITEM1 100
#define P_ITEM2 100
#define P_ITEM3 100
#define P_ITEM4 100
#define P_ITEM5 100
#define P_ITEM6 100
#define P_ITEM7 100



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