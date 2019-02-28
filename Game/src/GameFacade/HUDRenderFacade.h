#pragma once
#include "RenderIrrlicht.h"


class HUDRenderFacade
{
    private:
        IGUIEnvironment* env;
        IGUIImage* background;
        IGUIImage* life;
        IGUIImage* shield;

    public:
        HUDRenderFacade(){ init(); }

        ~HUDRenderFacade(){clear();}

        void init();
        void clear();
        void updateValues(float life, float shield, float fps, int score, int spawns, int weapon); 

};