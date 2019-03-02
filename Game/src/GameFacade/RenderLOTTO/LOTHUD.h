#pragma once
#include "FHUD.h"

class LOTHUD : public FHUD
{
    public:
        LOTHUD() : FHUD(){}
        ~LOTHUD(){}
        void init();
        void clear();
        void updateValues(float life, float shield, float fps, int score, int spawns, int weapon);
};