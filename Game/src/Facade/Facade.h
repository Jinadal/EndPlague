#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include "math_3d.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Facade
{
    private:
        bool play = true;
    public:
        GLFWwindow* initWindow();
        void processInput(GLFWwindow *window);
        void shutDown(){ play = false;};
        bool getPlay(){ return play;};
};