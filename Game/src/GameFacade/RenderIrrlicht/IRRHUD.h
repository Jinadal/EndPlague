#pragma once
#include "FHUD.h"
#include "IRRRender.h"


class IRRHUD : public FHUD
{
    private:
        irr::gui::IGUIEnvironment* env;
        irr::gui::IGUIImage* background;
        irr::gui::IGUIImage* life;
        irr::gui::IGUIImage* shield;

    public:
        IRRHUD() : FHUD() { init(); }

        ~IRRHUD(){clear();}

        void init();
        void clear();
        void updateValues(float life, float shield, float fps, int score, int spawns, int weapon); 

};