#pragma once
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <GL/glew.h>
#include <glm/ext.hpp>

class TResource
{
    protected:
        const char* name;
    public:
        TResource(){};
        virtual ~TResource(){};

        virtual bool loadResource() = 0;
        virtual void draw() = 0;

        virtual const char* getName(){ return name;};
        virtual void setName(const char* n);
};
