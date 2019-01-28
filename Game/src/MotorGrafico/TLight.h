#include "TEntity.h"
#include <GL/glew.h>
#include <glm/ext.hpp>

class TLight : public TEntity
{
    private:
        TColour  intesity;
    public:
        TLight(/* args */);
        ~TLight();

        void setIntesity(TColour c);
        TColour getIntensity();
        void beginDraw();
        void endDraw();
};