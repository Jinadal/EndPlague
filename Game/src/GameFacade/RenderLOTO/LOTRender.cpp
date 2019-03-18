#include "LOTRender.h"
#include "LOTMesh.h"
#include "LOTCamera.h"
#include "LOTHUD.h"
#include "LOTMenu.h"


LOTRender::LOTRender()
{
    loto = new Loto();
    window = loto->initWindow();
    manager = loto->getManager();
    loto->initRoot();
    loto->initOpenGL();
    scene = loto->getSceneRoot();
    scene->setId(0);
    

    loto->createNodeMesh(scene, glm::vec3(0,0,0), "nanosuit/nanosuit.obj");

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
