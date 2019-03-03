#pragma once
#include "FHUD.h"

class LOTHUD : public FHUD
{
    private:
        LOTHUD() : FHUD(){}

    public:

        static LOTHUD* getInstance()
        {
            static LOTHUD only_instance;
            return &only_instance;
        }

        ~LOTHUD(){}
        void init();
        void clear();
        void updateValues(float life, float shield, float fps, int score, int spawns, int weapon);
};