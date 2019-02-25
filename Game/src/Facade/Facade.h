#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "../MotorGrafico/TNode.h"
#include "../MotorGrafico/TCamera.h"
#include "../MotorGrafico/TLight.h"
#include "../MotorGrafico/TMesh.h"
#include "../MotorGrafico/TTransform.h"
#include "../MotorGrafico/TResourceManager.h"

class Facade
{
    private: 
        TNode* scene;
        TResourceManager* manager;
    public:
        GLFWwindow* initWindow();
        bool openWindow(GLFWwindow* w);
        void processInput(GLFWwindow *window);
        void clear(GLFWwindow* w);

        //TREE METHODS
        TNode* createNodeMesh(TNode* f, glm::vec3 v, const char* mesh);   
        TNode* createNodeLigth(TNode* f, glm::vec3 v, glm::vec4 i);
        TNode* createNodeCamera(TNode* f, glm::vec3 m, glm::vec3 v, float n,float ff,float t,float b,float r,float l);


        TNode* createBranch(TNode* f, glm::vec3 v);
};