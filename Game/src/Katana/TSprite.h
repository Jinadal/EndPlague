#pragma once
#include "Texture2D.h"
class TSprite
{
    private:
        Texture2D* texture;
        glm::vec2 position;
        glm::vec2 size;
        float rotate = 0.f;
        glm::vec3 color;

    public:
        TSprite(char* path);
        ~TSprite(){delete texture;}
        Texture2D* getTexture(){return texture;}
};