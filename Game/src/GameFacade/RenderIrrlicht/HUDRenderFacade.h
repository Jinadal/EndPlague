#pragma once
#include "RenderIrrlicht.h"


class HUDRenderFacade
{
    private:
        irr::gui::IGUIEnvironment* env;
        irr::gui::IGUIImage* background;
        irr::gui::IGUIImage* life;
        irr::gui::IGUIImage* shield;

    public:
        HUDRenderFacade(){ init(); }

        ~HUDRenderFacade(){clear();}

        void init();
        void clear();
        void updateValues(float life, float shield, float fps, int score, int spawns, int weapon); 

};