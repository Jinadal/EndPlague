#pragma once
#include "Texture2D.h"
#include "../../lib/glm/glm.hpp"

class TSprite
{
    private:
        Texture2D* texture;
        char* path;
        int width, height;
    public:
        glm::vec2 position = glm::vec2(0, 0);
        glm::vec2 size = glm::vec2(10, 10);
        float rotation = 0.f;
        glm::vec3 color = glm::vec3(1.f, 1.f, 1.f);

        TSprite(char* path);
        ~TSprite(){delete texture;}
        Texture2D* getTexture(){return texture;}
        void setPosition(int x, int y);
        void setSize(int x, int y);
        void setRotation(float r);
        void setColor(int r, int g, int b);
};