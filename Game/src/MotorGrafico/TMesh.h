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
        void beginDraw();
        void endDraw();
        
};
