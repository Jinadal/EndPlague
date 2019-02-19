#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Facade
{
    private:
        bool play = true;

        glm::vec3 aPos;
        glm::vec4 Position;

        GLuint vertexShader;
        GLuint fragmentShader;
        GLuint shaderProgram;
        
    public:
        void initWindow();
        void processInput(GLFWwindow *window);
        void shutDown(){ play = false;};
        bool getPlay(){ return play;};
        void drawTriangle();
};