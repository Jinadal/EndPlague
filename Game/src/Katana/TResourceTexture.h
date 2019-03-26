#pragma once
#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#include "TResource.h"
class TResource;
class TResourceTexture : public TResource
{
private:
    GLuint textureID;
    bool active;
public:
    TResourceTexture(){}
    ~TResourceTexture(){ glDeleteTextures(1, &textureID);};

    bool loadResource(); 
    void draw();

    void setActivate(bool b){active = b;};
    bool getActive(){ return active;};
};
