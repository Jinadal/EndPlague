#include "GameResource.h"
#include "GameObject.h"
#include "RenderManager.h"
#include "CollisionManager.h"


enum ItemType
{
    ITEM_1,
    ITEM_2
};

struct Type{
    ItemType type;
    char* mesh;
    char* texture;
};

Type iemtypes [2] = 
{
    {
        ITEM_1,
        (char*)"res/Itemy.obj",
        (char*)"res/red.bmp"
    },
    {
        ITEM_2,
        (char*)"res/Itemy.obj",
        (char*)"res/red.bmp"
    }
};

class ItemFabric
{
    private:
    public:
        ItemFabric(){}
        virtual ~ItemFabric(){}

        GameObject* createItem(float x, float y, float z, float rz, ItemType type);
};


