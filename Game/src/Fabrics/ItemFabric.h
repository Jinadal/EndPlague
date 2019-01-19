#pragma once
#include "GameObject.h"


enum ItemTypes
{
    ITEM_0,
    ITEM_1,
    ITEM_2,
    ITEM_3,
    ITEM_4, 
    ITEM_5, 
    ITEM_6,
    ITEM_7
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
        IType item_types [8] = 
        {
            {
                ITEM_0,
                (char*)"res/ITEM.obj",
                (char*)"res/ITEM.bmp", 
                0.f

            },
            {
                ITEM_1,
                (char*)"res/ITEM.obj",
                (char*)"res/ITEM.bmp", 
                1.f

            },
            {
                ITEM_2,
                (char*)"res/ITEM.obj",
                (char*)"res/ITEM.bmp",
                2.f
            }, 
            {
                ITEM_3,
                (char*)"res/ITEM.obj",
                (char*)"res/ITEM.bmp", 
                3.f
            },
            {
                ITEM_4,
                (char*)"res/ITEM.obj",
                (char*)"res/ITEM.bmp", 
                0.f

            },
            {
                ITEM_5,
                (char*)"res/ITEM.obj",
                (char*)"res/ITEM.bmp", 
                0.f

            },
            {
                ITEM_6,
                (char*)"res/ITEM.obj",
                (char*)"res/ITEM.bmp", 
                0.f

            },
            {
                ITEM_7,
                (char*)"res/ITEM.obj",
                (char*)"res/ITEM.bmp", 
                0.f

            }
        };

    public:
        ItemFabric(){}
        virtual ~ItemFabric(){}

        GameObject* createItem(float x, float y, float z, float rz, ItemTypes type);
};


