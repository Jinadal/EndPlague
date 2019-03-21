#pragma once
#include "FHUD.h"

class KATHUD : public FHUD
{
    private:
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