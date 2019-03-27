#pragma once
#include "TEntity.h"
#include "TResourceTexture.h"
class TBillboard : public TEntity
{
    private:
        TResourceTexture* texture;
        GLuint buffer;
        glm::vec3 position;

    public:
        TBillboard(TResourceTexture* t, glm::vec3 p);
        ~TBillboard(){}

        TResourceTexture* getTexture(){ return texture;};
        glm::vec3 getPosition(){ return position;};
        void setTexture(TResourceTexture* t){ texture = t;};
        void setPosition(glm::vec3 p){ position = p;};

        void beginDraw();
        void endDraw(){};
};