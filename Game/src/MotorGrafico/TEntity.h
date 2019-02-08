#include <iostream>
#include <stack>
#include <GL/glew.h>
#include <glm/ext.hpp>

class TEntity
{
    private:
        //static glm::mat4* matrix;
    public:
        TEntity(){}
        virtual ~TEntity(){}

        virtual void beginDraw() = 0;
        virtual void endDraw() = 0;


    //Static matrix in order to make the unique and global to their childs
    static glm::mat4& modelMatrix() 
    {
        static glm::mat4 matrix;
        return matrix;
    };
    static glm::mat4& viewMatrix() 
    {
        static glm::mat4 matrix;
        return matrix;
    };
    static glm::mat4& projectionMatrix() 
    {
        static glm::mat4 matrix;
        return matrix;
    };
    static std::stack<glm::mat4>& stackMatrix() 
    {
        static std::stack<glm::mat4> stackMatrix;
        return stackMatrix;
    };
};