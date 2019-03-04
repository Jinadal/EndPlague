#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "../MotorGrafico/TNode.h"
#include "../MotorGrafico/TCamera.h"
#include "../MotorGrafico/TLight.h"
#include "../MotorGrafico/TMesh.h"
#include "../MotorGrafico/TTransform.h"
#include "../MotorGrafico/TResourceManager.h"
#include "../MotorGrafico/TResourceMesh.h"
#include "../MotorGrafico/TResourceShader.h"

class Facade
{
    private: 
        GLFWwindow* window;
        TNode* scene;
        TNode* camera;
        TResourceManager* manager;

    public:
        GLFWwindow* initWindow();
        bool openWindow(GLFWwindow* w);
        void processInput(GLFWwindow *window);
        void clear(GLFWwindow* w);

        TResourceManager* getManager(){return manager;};
        void clean();
        void initOpenGL();
        void renderCamera();
        void updateCamera(glm::vec3 p,glm::vec3);
        //TREE METHODS
        void initRoot();
        TNode* getSceneRoot() { return scene; }
        TNode* createNodeMesh(TNode* f, glm::vec3 v, const char* mesh);   
        TNode* createNodeLigth(TNode* f, glm::vec3 v, glm::vec4 i);
        TNode* createNodeCamera(TNode* f, glm::vec3 m, glm::vec3 v, float n,float ff,float t,float b,float r,float l);

        TNode* createBranch(TNode* f, glm::vec3 v);
};