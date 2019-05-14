#pragma once
#include "TResource.h"
#include "TResourceOBJ.h"
#include "TResourceMaterial.h"
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>
class TResourceAnimation : public TResource
{
    protected:
        int frames = 1;
        std::vector<TResourceOBJ*> frame;
    public:
        TResourceAnimation(int f){ frames = f;};
        ~TResourceAnimation();

        void setFrames(int f){frames = f;};
        int getFrames(){return frames;};

        bool loadResource();
        void draw(){};
};
