#pragma once
#include "TResource.h"

class TResourceMaterial : public TResource
{
private:
    /* data */
public:
    TResourceMaterial(){}
    ~TResourceMaterial(){}

    bool loadResource(){return false;}; 
    void draw(){};
};
