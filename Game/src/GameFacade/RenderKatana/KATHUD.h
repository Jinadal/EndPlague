#pragma once
#include "FHUD.h"

class TSprite;
class KATHUD : public FHUD
{
    private:
        TSprite* background;
        TSprite* life;
        TSprite* shield;
        TSprite* weapon;
        //TSprite* score1;
        //TSprite* score2;
        //TSprite* score3;
        //TSprite* score4;
        //TSprite* score5;


        int scoreNum;
        int weaponType = 2;
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