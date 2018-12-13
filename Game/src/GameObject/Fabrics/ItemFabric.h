#include "GameResource.h"
#include "GameObject.h"
#include "RenderManager.h"
#include "CollisionManager.h"
#include "ItemManager.h"


enum ItemType
{
    ITEM_1,
    ITEM_2, 
    ITEM_3
};

struct Type{
    ItemType type;
    char* mesh;
    char* texture;
};

Type itemtypes [3] = 
{
    {
        ITEM_1,
        (char*)"res/Enemyy.obj",
        (char*)"res/red.bmp"
    },
    {
        ITEM_2,
        (char*)"res/Enemyy.obj",
        (char*)"res/red.bmp"
    }, 
    {
        ITEM_3,
        (char*)"res/Enemyy.obj",
        (char*)"res/red.bmp"
    }
};

class ItemFabric
{
    private:
        GameResource*       gameresource        = GameResource::getInstance();
        RenderManager*      rendermanager       = RenderManager::getInstance();
        CollisionManager*   collisionmanager    = CollisionManager::getInstance();
        ItemManager*        itemmanager         = ItemManager::getInstance();

    public:
        ItemFabric(){}
        virtual ~ItemFabric(){}

        GameObject* createItem(float x, float y, float z, float rz, ItemType type);
};


