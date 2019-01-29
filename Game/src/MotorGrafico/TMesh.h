#include "TEntity.h"
#include "TResource.h"
#include <GL/glew.h>
#include <glm/ext.hpp>


class TMesh : public TEntity
{
    private:
        TResource* mesh;
    public:
        TMesh(/* args */);
        ~TMesh();

        //Get & Set
        void setMesh(TResource* m){ mesh = m;};
        TResource* getMesh(){ return mesh;};

        void beginDraw();
        void endDraw(){};
        
};
