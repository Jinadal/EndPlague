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

        //Get & Set
        void setIntesity(TColour c);
        TColour getIntensity(){ return intesity;};

        void beginDraw();
        void endDraw();
};