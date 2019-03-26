#include "Katana.h"
#include <../common/shader.cpp>
// Include GLM
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL 
#include <iostream>
#include "GameValues.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);


void MessageCallback( GLenum source,
                      GLenum type,
                      GLuint id,
                      GLenum severity,
                      GLsizei length,
                      const GLchar* message,
                      const void* userParam )
{
  fprintf( stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
           ( type == GL_DEBUG_TYPE_ERROR ? " GL ERROR " : "" ),
            type, severity, message );
}



GLFWwindow* Katana::initWindow()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    window = glfwCreateWindow(gv::SCR_WIDTH, gv::SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
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

void Katana::initRoot()
{
    scene = new TNode();
    manager = new TResourceManager();

    glm::mat4& Projection = scene->getEntity()->projectionMatrix();
    Projection = glm::mat4(1.0f);
    glm::mat4& View = scene->getEntity()->viewMatrix();
    View = glm::mat4(1.0f);
    glm::mat4& Model = scene->getEntity()->modelMatrix();
    Model = glm::mat4(1.0f);
    
}

bool Katana::openWindow(GLFWwindow* w)
{
    return !glfwWindowShouldClose(w);
}

void Katana::clear(GLFWwindow* w)
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(w);
    glfwPollEvents();
}
// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void Katana::processInput(GLFWwindow *window)
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
TNode* Katana::createNodeMesh(TNode* f, glm::vec3 v, const char* m)
{
    if(f!= nullptr)
    {
        //Be sure that the father is a root or a transformation node
        if(f->getEntity() == nullptr || dynamic_cast<TTransform*>(f->getEntity()) != nullptr)
        {
            //Creates a 3 node branch with their respective transformations
            TNode* nodeRST = createBranch(f,v);
            
            //Mesh Leaf, load in memory mesh and assign it
            TMesh* mesh = new TMesh();
            TResourceOBJ* mm = manager->getResourceOBJ(m);
            mesh->setMesh((TResource*) mm);
            
            TNode* nodeMesh = new TNode(nodeRST,mesh);
            nodeMesh->setId(4);
            nodeRST->addChild(nodeMesh);

            return nodeMesh;
        }
    }
    return nullptr;
}

TNode* Katana::createNodeLigth(TNode* f, glm::vec3 v, glm::vec4 i)
{
    if(f->getEntity() == nullptr || dynamic_cast<TTransform*>(f->getEntity()) != nullptr)
    {
        //Creates a 3 node branch with their respective transformations
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

TNode* Katana::createNodeCamera(TNode* f, glm::vec3 p, glm::vec3 v, float n,float ff)
{
    if(f->getEntity() == nullptr || dynamic_cast<TTransform*>(f->getEntity()) != nullptr)
    {
        TNode* nodeRST = createBranch(f,v);

        //Camera Leaf
        TCamera* c = new TCamera();
        TNode* nodeCamera = new TNode(nodeRST, c);
        nodeCamera->setId(5);
        nodeRST->addChild(nodeCamera);
        camera = nodeCamera;
        calculateCamera(p,v);

        return camera;
    }
    return nullptr;
}

TNode* Katana::createBranch(TNode* f, glm::vec3 v)
{
    //Rotation node
    TTransform* tr = new TTransform();
    tr->identity();
    TNode* nodeRot = new TNode(f, tr);
    nodeRot->setId(1);

    f->addChild(nodeRot);

    //Scale node
    TTransform* ts = new TTransform();
    ts->identity();
    TNode* nodeSca = new TNode(nodeRot, ts);
    nodeSca->setId(2);
    nodeRot->addChild(nodeSca);

    //Translation node
    TTransform* tt = new TTransform();
    tt->identity();
    tt->translate(v.x,v.y,v.z);
    TNode* nodeTrans = new TNode(nodeSca, tt);
    nodeTrans->setId(3);

    nodeSca->addChild(nodeTrans);

    return nodeTrans;
}

void Katana::clean()
{
    delete manager;
    delete scene;
}

void Katana::initOpenGL()
{

    const char * vshader_path   = "src/Katana/shaders/TransformVertexShader.vertexshader";
    const char * fshader_path   = "src/Katana/shaders/TextureFragmentShader.fragmentshader";

    GLenum res = glewInit();
    if (res != GLEW_OK)
    {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
    }

    TResourceShader* vertexShader   = manager->getResourceShader(vshader_path, (GLenum)GL_VERTEX_SHADER);
	TResourceShader* fragmentShader = manager->getResourceShader(fshader_path, (GLenum)GL_FRAGMENT_SHADER);

    GLuint vertexID     = vertexShader->getId();
	GLuint fragmentID   = fragmentShader->getId();

    GLuint shaderProgram = glCreateProgram();
    
    glAttachShader(shaderProgram, vertexID);
    glAttachShader(shaderProgram, fragmentID);
    glLinkProgram(shaderProgram);
    glValidateProgram(shaderProgram);

    glDetachShader(shaderProgram, vertexID);
	glDetachShader(shaderProgram, fragmentID);

    glDeleteShader(vertexID);
    glDeleteShader(fragmentID);

    //Enable Z-Buffer 
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS); 
	glEnable(GL_CULL_FACE);
    
    glUseProgram(shaderProgram);

    scene->getEntity()->setProgramID(shaderProgram);

    GLuint view         = glGetUniformLocation(shaderProgram, "V");
    GLuint model        = glGetUniformLocation(shaderProgram, "M");
    GLuint projection   = glGetUniformLocation(shaderProgram, "ProjectionMatrix");
	GLuint matrix       = glGetUniformLocation(shaderProgram, "MVP");
	GLuint TextureID    = glGetUniformLocation(shaderProgram, "myTextureSampler");
    GLuint light        = glGetUniformLocation(shaderProgram, "light_pos");

    scene->getEntity()->setviewID(view);
    scene->getEntity()->setmodelID(model);
    scene->getEntity()->setprojectionID(projection);
	scene->getEntity()->setMVPID(matrix);
    glUniform1i(TextureID, 0);
}

void Katana::deleteNodeBranch(TNode* n)
{
    if(n!=nullptr)
    {
        TNode* d = n->getFather()->getFather()->getFather();
        if(d != nullptr && dynamic_cast<TTransform*>(d->getEntity()) != nullptr)
            scene->remChild(n);            
    }
}

void Katana::renderCamera()
{

    if(camera != nullptr)
    {
        glUniformMatrix4fv(scene->getEntity()->getViewID(), 1, GL_FALSE, &scene->getEntity()->viewMatrix()[0][0]);
    }
}

void Katana::calculateCamera(glm::vec3 p,glm::vec3 t)
{
    scene->getEntity()->viewMatrix() = glm::lookAt(p,t,glm::vec3(0,1,0));   
}


void Katana::drawAll()
{
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Use our shader
    scene->draw();

    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Katana::close()
{

	glDeleteProgram(scene->getEntity()->getProgramID());
	//glDeleteTextures(1, &Texture);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
}
