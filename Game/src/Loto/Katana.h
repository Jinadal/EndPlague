#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glew.h>
#define GLM_ENABLE_EXPERIMENTAL 

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "TNode.h"
#include "TCamera.h"
#include "TLight.h"
#include "TMesh.h"
#include "TTransform.h"
#include "TResourceManager.h"
#include "TResourceOBJ.h"
#include "TResourceShader.h"

class Katana
{
    private: 
        GLFWwindow* window;
        TNode* scene;
        TNode* camera;
        TResourceManager* manager;

    public:
        GLFWwindow* initWindow();
        bool openWindow(GLFWwindow* w);
        bool run();
        void processInput(GLFWwindow *window);
        void clear();
        void postDraw(GLFWwindow* w);

        TResourceManager* getManager(){return manager;};
        void clean();
        void initOpenGL();
        void renderCamera();
        void calculateCamera(glm::vec3 p,glm::vec3 t);

        //TREE METHODS
        void initRoot();
        TNode* getSceneRoot() { return scene; }
        TNode* createNodeMesh(TNode* f, glm::vec3 v, const char* mesh);   
        TNode* createNodeLigth(TNode* f, glm::vec3 v, glm::vec4 i);
        TNode* createNodeCamera(TNode* f, glm::vec3 m, glm::vec3 v, float n,float ff);

        TNode* createBranch(TNode* f, glm::vec3 v);
};