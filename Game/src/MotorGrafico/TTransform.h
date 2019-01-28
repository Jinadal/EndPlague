#include "TEntity.h"
#include <GL/glew.h>
#include <glm/ext.hpp>

class TTransform : public TEntity
{
    private:
        TMatrix4x4 matrix;
    public:
        TTransform(/* args */);
        ~TTransform();

        void identity();
        void load(TMatrix4x4 matrix);
        void transpose();
        void translate(float,float,float,float);
        void rotate(float,float,float,float);
        void beginDraw();
        void endDraw();
};
