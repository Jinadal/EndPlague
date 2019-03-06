#pragma once
#include "FMesh.h"

class LOTMesh : public FMesh 
{
    public:
        LOTMesh(){}
        ~LOTMesh(){}

        void setPosition(float x, float y, float z);
        void setRotation(float x, float y, float z);
        void setVisible(bool b);
        void setTexture(char* s);
        void isMap();
};

