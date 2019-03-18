#pragma once
#include "FMesh.h"
#include "TNode.h"
class LOTMesh : public FMesh 
{
    private:
        TNode* mesh;
    public:
        LOTMesh(){}
        ~LOTMesh(){}

        void setPosition(float x, float y, float z);
        void setRotation(float x, float y, float z);
        void setVisible(bool b);
        void setTexture(char* s);
        void isMap();


        void setMesh(TNode* node){mesh = node;}
};

