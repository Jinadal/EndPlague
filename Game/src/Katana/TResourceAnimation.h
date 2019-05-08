#pragma once
#include "TResource.h"

class TResourceAnimation : public TResource
{
    protected:

    public:
        TResourceAnimation(){};
        ~TResourceAnimation(){};

        bool loadResource(){return false;};
        void draw(){};
};
