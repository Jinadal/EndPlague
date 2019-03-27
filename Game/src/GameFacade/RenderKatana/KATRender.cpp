#include "KATRender.h"
#include "KATMesh.h"
#include "KATCamera.h"
#include "KATHUD.h"
#include "KATMenu.h"


KATRender::KATRender()
{
    katana = new Katana();
	window = katana->initWindow();
    katana->initRoot();
	katana->initOpenGL();
    scene = katana->getSceneRoot();

	katana->createNodeCamera(scene, glm::vec3(-0,-0,-1),glm::vec3(0,0,0),0.1f,100.0f);
    //katana->createBillboard("res/sprites/Menu.png",glm::vec3(0,0,0));
}

void KATRender::drawAll()
{
    katana->drawAll();
}

bool KATRender::run()
{
    return katana->openWindow(window);
}

void KATRender::drop()
{
    katana->close();
}

float KATRender::getCursorX()
{
    return katana->cursorPosition().x;
}

float KATRender::getCursorY()
{
    return katana->cursorPosition().y;
}

FMesh* KATRender::createMesh(char* s)
{
    KATMesh* r = new KATMesh();
    r->setMesh(katana->createNodeMesh(scene,glm::vec3(0,0,0),s));
    return r;
}

FCamera* KATRender::createCamera()
{
    return new KATCamera();
}

FHUD* KATRender::getHUD()
{

    return KATHUD::getInstance();
}

FMenu* KATRender::getMenu()
{
    return KATMenu::getInstance();
}


void KATRender::setCamera(float x,float y,float z,float rx,float ry,float rz)
{
    katana->calculateCamera(glm::vec3(x, y, z),glm::vec3(rx, ry, rz));
}


void KATRender::deleteNode(TNode* n)
{
    katana->deleteNodeBranch(n);
}



TBillboard* KATRender::createBillboard(char* t,float x, float y, float z)
{
	TBillboard* bill = katana->createBillboard(t,glm::vec3(x, y, z));
    
}