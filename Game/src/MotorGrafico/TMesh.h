#include "TEntity.h"
#include <GL/glew.h>
#include <glm/ext.hpp>

class TMesh : public TEntity
{
    private:
        TResource* mesh
    public:
        TMesh(/* args */);
        ~TMesh();

        void loadMesh(TResource* m){ mesh=m;};
        TResource getMesh(){ return mesh;};
        void beginDraw();
        void endDraw();
        
};
