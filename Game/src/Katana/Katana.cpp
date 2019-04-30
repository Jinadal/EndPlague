#include "Katana.h"
#include "../common/shader.cpp"
// Include GLM
#include "../../lib/glm/glm.hpp"
#define GLM_ENABLE_EXPERIMENTAL 
#include <iostream>
#include "GameValues.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);


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
    window = glfwCreateWindow(gv::SCR_WIDTH, gv::SCR_HEIGHT, "Screams In Goblin", NULL, NULL);
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
        TNode* nodeRST = createBranch(f,p);
        setCameraPosition(p.x, p.y, p.z);
        //Camera Leaf
        TCamera* c = new TCamera();
        TNode* nodeCamera = new TNode(nodeRST, c);
        nodeCamera->setId(10);
        nodeRST->addChild(nodeCamera);
        camera = nodeCamera;

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
    const char * vbill_path     = "src/Katana/shaders/billboard.vert";
    const char * gbill_path     = "src/Katana/shaders/billboard.geo";
    const char * fbill_path     = "src/Katana/shaders/billboard.frag";

    GLenum res = glewInit();
    if (res != GLEW_OK)
    {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
    }

    TResourceShader* vertexShader   = manager->getResourceShader(vshader_path, (GLenum)GL_VERTEX_SHADER);
	TResourceShader* fragmentShader = manager->getResourceShader(fshader_path, (GLenum)GL_FRAGMENT_SHADER);
    TResourceShader* vbillShader    = manager->getResourceShader(vbill_path, (GLenum)GL_VERTEX_SHADER);
    TResourceShader* gbillShader    = manager->getResourceShader(gbill_path, (GLenum)GL_GEOMETRY_SHADER);
    TResourceShader* fbillShader    = manager->getResourceShader(fbill_path, (GLenum)GL_FRAGMENT_SHADER);

    GLuint vertexID     = vertexShader->getId();
	GLuint fragmentID   = fragmentShader->getId();
    GLuint vbillID      = vbillShader->getId();
    GLuint gbillID      = gbillShader->getId();
    GLuint fbillID      = fbillShader->getId();

    GLuint shaderProgram = glCreateProgram();
    billboardProgram = glCreateProgram();
    
    glAttachShader(shaderProgram, vertexID);
    glAttachShader(shaderProgram, fragmentID);
    glLinkProgram(shaderProgram);
    glValidateProgram(shaderProgram);
  

    glDetachShader(shaderProgram, vertexID);
	glDetachShader(shaderProgram, fragmentID);

    glDeleteShader(vertexID);
    glDeleteShader(fragmentID);

    glAttachShader(billboardProgram, vbillID);
    glAttachShader(billboardProgram, gbillID);
    glAttachShader(billboardProgram, fbillID);
    glLinkProgram(billboardProgram);
    glValidateProgram(billboardProgram);

    GLint Result = GL_FALSE;
    int InfoLogLength;
    glGetProgramiv(billboardProgram, GL_LINK_STATUS, &Result);
	glGetProgramiv(billboardProgram, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> ProgramErrorMessage(InfoLogLength+1);
		glGetProgramInfoLog(billboardProgram, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
    }

    glDetachShader(billboardProgram, vbillID);
	glDetachShader(billboardProgram, gbillID);
    glDetachShader(billboardProgram, fbillID);

    glDeleteShader(vbillID);
    glDeleteShader(gbillID);
    glDeleteShader(fbillID);
    //Enable Z-Buffer 
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS); 
	glEnable(GL_CULL_FACE);

    scene->getEntity()->setProgramID(shaderProgram);

    GLuint view         = glGetUniformLocation(shaderProgram, "V");
    GLuint model        = glGetUniformLocation(shaderProgram, "M");
    GLuint projection   = glGetUniformLocation(shaderProgram, "ProjectionMatrix");
	GLuint matrix       = glGetUniformLocation(shaderProgram, "MVP");
	//GLuint TextureID    = glGetUniformLocation(shaderProgram, "myTextureSampler");
    //GLuint light        = glGetUniformLocation(shaderProgram, "light_pos");

    scene->getEntity()->setviewID(view);
    scene->getEntity()->setmodelID(model);
    scene->getEntity()->setprojectionID(projection);
	scene->getEntity()->setMVPID(matrix);

    glUseProgram(shaderProgram);

}

void Katana::deleteNodeBranch(TNode* n)
{
    if(n!=nullptr)
    {
        TNode* d = n->getFather()->getFather()->getFather();
        if(d != nullptr && dynamic_cast<TTransform*>(d->getEntity()) != nullptr)
            scene->remChild(d);            
    }
}

void Katana::renderCamera()
{
    
    
    glm::mat4 tm  = ((TTransform*) camera->getFather()->getEntity())->getMatrix();
    glm::mat4 sm  = ((TTransform*) camera->getFather()->getFather()->getEntity())->getMatrix();
    glm::mat4 rm  = ((TTransform*) camera->getFather()->getFather()->getFather()->getEntity())->getMatrix();

    glm::mat4 fm = tm * sm * rm;
    scene->getEntity()->viewMatrix() = glm::inverse(fm);

    //if(camera != nullptr)
    //{
    //    glUniformMatrix4fv(scene->getEntity()->getViewID(), 1, GL_FALSE, &scene->getEntity()->viewMatrix()[0][0]);
    //}
}

void Katana::drawAll()
{
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(billboardProgram);

	renderBillboards();
    glUseProgram(scene->getEntity()->getProgramID());
    renderCamera();

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

TBillboard* Katana::createBillboard(const char* n, glm::vec3 p)
{
	TResourceTexture* t = manager->getResourceTexture(n);
	TBillboard* b = new TBillboard(t, p);
	billboards.push_back(b);

	return b;
}
void Katana::renderBillboards()
{
    
	glm::mat4 v         = scene->getEntity()->viewMatrix();
	glm::mat4 p         = scene->getEntity()->projectionMatrix();
	glm::mat4 PV        = p * v;
	glm::vec3 camPos    = glm::vec3(-v[3][2], -v[3][1], -v[3][0]);
    
    GLuint PVID     = glGetUniformLocation(billboardProgram, "gVP");
    GLuint camID    = glGetUniformLocation(billboardProgram, "gCameraPos");

    glUniformMatrix4fv(PVID,1,GL_FALSE,&PV[0][0]);
    glUniform3fv(camID, 1, &camPos[0]);

	for(unsigned int i = 0; i < billboards.size(); i++)
	{
		billboards[i]->beginDraw();
	}
}

CursorXYZ Katana::cursorPosition()
{
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    float x = 2 * xpos/width -1;
    float y = 1 - 2 * ypos/height;
    float z = 1.0f;

    glm::vec3 ray_nds = glm::vec3(x, y, z);
    glm::vec4 ray_clip = glm::vec4(ray_nds.x, ray_nds.y, -1.0, 1.0);
    glm::vec4 ray_eye = glm::inverse(scene->getEntity()->projectionMatrix()) * ray_clip;
    ray_eye = glm::vec4(ray_eye.x, ray_eye.y, -1.0, 0.0);

    glm::vec3 ray_wor = (glm::inverse(scene->getEntity()->viewMatrix()) * ray_eye);

    //ray_wor = glm::normalize(ray_wor);

    x = cameraPos.x - ((cameraPos.z * ray_wor.x) / ray_wor.z);
    y = cameraPos.y - ((cameraPos.z * ray_wor.y) / ray_wor.z);

    return CursorXYZ{-x, y, 0.f};
}


void Katana::setCameraPosition(float x, float y, float z)
{
    cameraPos.x = x;
    cameraPos.y = y;
    cameraPos.z = z;
}


void Katana::renderEnvoirment()
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, gv::SCR_WIDTH, gv::SCR_HEIGHT, 0.0, -1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    //glPushMatrix();        ----Not sure if I need this
    glLoadIdentity();
    glDisable(GL_CULL_FACE);

    glClear(GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0);
        glVertex2f(0.0, 0.0);
        glVertex2f(10.0, 0.0);
        glVertex2f(10.0, 10.0);
        glVertex2f(0.0, 10.0);
    glEnd();

// Making sure we can render 3d again
glMatrixMode(GL_PROJECTION);
glPopMatrix();
glMatrixMode(GL_MODELVIEW);
//glPopMatrix();        ----and this?
}