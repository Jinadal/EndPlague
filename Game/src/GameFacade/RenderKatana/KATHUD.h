#pragma once
#include "FHUD.h"

class TSprite;
class KATHUD : public FHUD
{
    private:
        TSprite* background;
        TSprite* life;
        
        KATHUD() : FHUD(){}

    public:

        static KATHUD* getInstance()
        {
            static KATHUD only_instance;
            return &only_instance;
        }

        ~KATHUD(){}
        void init();
        void clear();
        void updateValues(float life, float shield, float fps, int score, int spawns, int weapon);
};