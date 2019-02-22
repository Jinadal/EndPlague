#pragma once

class GameObject;
enum ItemTypes
{
    EMPTY,
    CROSSBOW,
    AXE,
    PEAK,
    POTION, 
    SHIELD,
};

struct IType{
    ItemTypes type;
    char* mesh;
    char* texture;
};



class ItemFabric
{
    private:
        IType item_types [8] = 
        {
            {
                EMPTY,
                (char*)"res/ITEM.obj",
                (char*)"res/ITEM.bmp"

            },
            {
                CROSSBOW,
                (char*)"res/Crossbow.obj",
                (char*)"res/ITEM.bmp"

            },
            {
                AXE,
                (char*)"res/ITEM.obj",
                (char*)"res/ITEM.bmp"
            }, 
            {
                PEAK,
                (char*)"res/Peak.obj",
                (char*)"res/ITEM.bmp"
            },
            {
                POTION,
                (char*)"res/Potion.obj",
                (char*)"res/ITEM.bmp"

            },
            {
                SHIELD,
                (char*)"res/Escudo.obj",
                (char*)"res/ITEM.bmp"
            }
        };

    public:
        ItemFabric(){}
        virtual ~ItemFabric(){}

        void createItem(float x, float y, float z, float rz, ItemTypes type);
};


