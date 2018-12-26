#pragma once
#include "GameResource.h"
#include "GameObject.h"
#include "RenderManager.h"
#include "BPhysicManager.h"
#include "ItemManager.h"


enum ItemTypes
{
    ITEM_1,
    ITEM_2,
    ITEM_3
};

struct IType{
    ItemTypes type;
    char* mesh;
    char* texture;
    float Itype;
};



class ItemFabric
{
    private:
        GameResource*       gameresource        = GameResource::getInstance();
        RenderManager*      rendermanager       = RenderManager::getInstance();
        BPhysicManager*     bphysicmanager      = BPhysicManager::getInstance();
        ItemManager*        itemmanager         = ItemManager::getInstance();

        IType item_types [3] = 
        {
            {
                ITEM_1,
                (char*)"res/ITEM.obj",
                (char*)"res/ITEM.bmp", 
                1

            },
            {
                ITEM_2,
                (char*)"res/ITEM.obj",
                (char*)"res/green.bmp",
                2
            }, 
            {
                ITEM_3,
                (char*)"res/ITEM.obj",
                (char*)"res/green.bmp", 
                3
            }
        };

    public:
        ItemFabric(){}
        virtual ~ItemFabric(){}

        GameObject* createItem(float x, float y, float z, float rz, int type);
};


