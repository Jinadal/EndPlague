#include "Facade.h"
#include <iostream>
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

GLFWwindow* Facade::initWindow()
{
   

    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        //return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    return window;
}
bool Facade::openWindow(GLFWwindow* w)
{
    return !glfwWindowShouldClose(w);
}

void Facade::clear(GLFWwindow* w)
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(w);
    glfwPollEvents();
}
// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void Facade::processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

//We create all the branch with the 3 transformations in the order ROT - SCA - TRANS
TNode* Facade::createNodeMesh(TNode* f, glm::vec3 v, const char* m)
{
    if(f->getEntity() == nullptr || dynamic_cast<TTransform*>(f->getEntity()) != nullptr)
    {
        TNode* nodeRST = createBranch(f,v);

        //Mesh Leaf
        TMesh* mesh = new TMesh();
        TResourceMesh* rm = manager->getResourceMesh(m);
        mesh->setMesh((TResource*) rm);
        TNode* nodeMesh = new TNode(nodeRST,mesh);
        nodeRST->addChild(nodeMesh);

        return nodeMesh;
    }
    return nullptr;
}

TNode* Facade::createNodeLigth(TNode* f, glm::vec3 v, glm::vec4 i)
{
    if(f->getEntity() == nullptr || dynamic_cast<TTransform*>(f->getEntity()) != nullptr)
    {
        TNode* nodeRST = createBranch(f,v);

        //light Leaf
        TLight* l = new TLight();
        l->setIntesity(i);
        l->setActivated(true);
        TNode* nodeLight = new TNode(nodeRST, l);
        nodeRST->addChild(nodeLight);

        return nodeLight;
    }
    return nullptr;
}
TNode* Facade::createNodeCamera(TNode* f, glm::vec3 m, glm::vec3 v, float n,float ff,float t,float b,float r,float l)
{
    if(f->getEntity() == nullptr || dynamic_cast<TTransform*>(f->getEntity()) != nullptr)
    {
        TNode* nodeRST = createBranch(f,v);

        //light Leaf
        TCamera* c = new TCamera();
        c->setCameraParametres( n, ff, t, b, r, l);
        TNode* nodeCamera = new TNode(nodeRST, c);
        nodeRST->addChild(nodeCamera);

        return nodeCamera;
    }
    return nullptr;
}

TNode* Facade::createBranch(TNode* f, glm::vec3 v)
{
    //Rotation node
    TTransform* tr = new TTransform();
    tr->identity();
    TNode* nodeRot = new TNode(f, tr);
    f->addChild(nodeRot);
    
    //Scale node
    TTransform* ts = new TTransform();
    ts->identity();
    TNode* nodeSca = new TNode(nodeRot, ts);
    nodeRot->addChild(nodeSca);

    //Translation node
    TTransform* tt = new TTransform();
    tt->identity();
    tt->translate(v.x,v.y,v.z);
    TNode* nodeTrans = new TNode(nodeSca, tt);
    nodeSca->addChild(nodeTrans);

    return nodeTrans;
}