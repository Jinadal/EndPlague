#pragma once

class GameObject;
enum ItemTypes
{
    ITEM_0,
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
        IType item_types [4] = 
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
            }
        };

    public:
        ItemFabric(){}
        virtual ~ItemFabric(){}

        GameObject* createItem(float x, float y, float z, float rz, ItemTypes type);
};


