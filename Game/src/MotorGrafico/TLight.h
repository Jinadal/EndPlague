#include "TEntity.h"
#include <GL/glew.h>
#include <glm/ext.hpp>

class TLight : public TEntity
{
    private:
        glm::vec4 intensity = glm::vec4(1.0,1.0,1.0,1.0);

    public:
        TLight(/* args */);
        ~TLight();

        //Get & Set
        void setIntesity(glm::vec4 i){ intensity = i;};
        glm::vec4 getIntensity(){ return intensity;};

        void beginDraw();
        void endDraw();
};