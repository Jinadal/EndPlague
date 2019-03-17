#pragma once
#include "TResourceMesh.h"

class TResourceOBJ : public TResource
{
    private:
        std::vector<TResourceMesh*> meshes;
    public:
        TResourceOBJ(){};
        ~TResourceOBJ(){};

        bool loadResource();
        void draw();

        std::vector<std::string> split(std::string str,std::string sep);
};