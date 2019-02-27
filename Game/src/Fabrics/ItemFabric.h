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
                (char*)"res/PEAK.obj",
                (char*)"res/PEAK.bmp"
            },
            {
                POTION,
                (char*)"res/POTION.obj",
                (char*)"res/POTION.bmp"

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


