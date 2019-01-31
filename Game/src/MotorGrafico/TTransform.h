#include "TEntity.h"
#include <GL/glew.h>
#include <glm/ext.hpp>

class TTransform : public TEntity
{
    private:
        glm::mat4 matrix;
    public:
        TTransform(/* args */);
        ~TTransform();

        //Get & Set
        void setMatrix(glm::mat4 m){ matrix = m;};
        glm::mat4 getMatrix(){ return matrix;};

        
        //Basic Transformations
        void translate(float x,float y,float z);
        void rotate(float x,float y,float z);
        void scale(float x, float y, float z);
        
        //Advance Transformations
        void transpose();
        void invert();
        void identity();

        void beginDraw();
        void endDraw();
};
