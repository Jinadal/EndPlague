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
                (char*)"res/obj/BALLESTA.obj",
                (char*)"res/tex/Ballesta_Color.bmp"

            },
            {
                AXE,
                (char*)"res/obj/HACHA.obj",
                (char*)"res/tex/Hacha_Color.bmp"
            }, 
            {
                PEAK,
                (char*)"res/obj/PICO.obj",
                (char*)"res/tex/Pico_Color.bmp"
            },
            {
                POTION,
                (char*)"res/obj/POCION.obj",
                (char*)"res/tex/Pocion_Color.bmp"

            },
            {
                SHIELD,
                (char*)"res/obj/ESCUDO.obj",
                (char*)"res/tex/Escudo_Color.bmp"
            }
        };

    public:
        ItemFabric(){}
        virtual ~ItemFabric(){}

        void createItem(float x, float y, float z, float rz, ItemTypes type);
};


