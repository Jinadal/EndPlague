#include "LOTRender.h"
#include "LOTMesh.h"
#include "LOTCamera.h"
#include "LOTHUD.h"
#include "LOTMenu.h"
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


LOTRender::LOTRender()
{

    
    loto = new Loto();
    window = loto->initWindow();
    manager = loto->getManager();
    loto->initRoot();
    loto->initOpenGL();
    scene = loto->getSceneRoot();
    scene->setId(0);
    TNode* camera = loto->createNodeCamera(scene,glm::vec3(10,10,25),glm::vec3(0,10,0),0.01f,1000.0f);
    loto->createNodeMesh(scene, glm::vec3(0,0,0), "nanosuit/nanosuit.obj");


    glEnable( GL_DEBUG_OUTPUT );
    glDebugMessageCallback( (GLDEBUGPROC) MessageCallback, 0 );
}
void LOTRender::drawAll()
{
    loto->clear(window);
    loto->renderCamera();
    scene->draw();
}

bool LOTRender::run()
{
    return loto->openWindow(window);
}

void LOTRender::drop()
{
    loto->clean();
    delete loto;
}

float LOTRender::getCursorX()
{
    return 0.f;
}

float LOTRender::getCursorY()
{
    return 0.f;
}

FMesh* LOTRender::createMesh(char* s)
{
    return new LOTMesh();
}

FCamera* LOTRender::createCamera()
{
    return new LOTCamera();
}

FHUD* LOTRender::getHUD()
{
    return LOTHUD::getInstance();
}

FMenu* LOTRender::getMenu()
{
    return LOTMenu::getInstance();
}
