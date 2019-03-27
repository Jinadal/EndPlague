#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../../lib/GL/glew.h"
#define GLM_ENABLE_EXPERIMENTAL 

#include "../../lib/GLFW/glfw3.h"
#include "../../lib/glm/glm.hpp"

#include "TNode.h"
#include "TCamera.h"
#include "TLight.h"
#include "TMesh.h"
#include "TBillboard.h"
#include "TTransform.h"
#include "TResourceManager.h"
#include "TResourceOBJ.h"
#include "TResourceShader.h"

struct CursorXYZ
{
    float x, y, z;
};

class Katana
{
    private: 
        GLFWwindow* window;
        TNode* scene;
        TNode* camera;
        TResourceManager* manager;
        std::vector<TBillboard*> billboards;
        std::vector<TResourceTexture*> hud;
        GLuint billboardProgram;
        glm::vec3 cameraPos = glm::vec3(0, 0, 0);
    public:
        GLFWwindow* initWindow();
        bool openWindow(GLFWwindow* w);
        void processInput(GLFWwindow *window);
        void clear(GLFWwindow* w);
        void close();

        TResourceManager* getManager(){return manager;};
        void clean();
        void initOpenGL();
        void renderCamera();
        void drawAll();
        void calculateCamera(glm::vec3 p,glm::vec3 t);

        //TREE METHODS
        void initRoot();
        TNode* getSceneRoot() { return scene; }
        TNode* createNodeMesh(TNode* f, glm::vec3 v, const char* mesh);   
        TNode* createNodeLigth(TNode* f, glm::vec3 v, glm::vec4 i);
        TNode* createNodeCamera(TNode* f, glm::vec3 m, glm::vec3 v, float n,float ff);
        TBillboard* createBillboard(const char* n, glm::vec3 p);
        void renderBillboards();
        void deleteNodeBranch(TNode* n);

        TNode* createBranch(TNode* f, glm::vec3 v);
        CursorXYZ cursorPosition();

        void createNodeTexture(char* name, glm::vec3 p);
        void renderTexture();
};