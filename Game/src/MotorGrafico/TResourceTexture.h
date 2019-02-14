#pragma once
#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#include "TResource.h"
class TResource;
class TResourceTexture : public TResource
{
private:
    GLuint textureID;

public:
    TResourceTexture(){}
    ~TResourceTexture(){}

    bool loadResource(); 
    void draw(){}
};
