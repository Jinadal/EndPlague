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
	//scene->setId(0);

	katana->createNodeCamera(scene, glm::vec3(10,0,5),glm::vec3(0,0,0),0.01f,1000.0f);
	katana->createNodeMesh(scene, glm::vec3(0,0,0),"nanosuit/nanosuit.obj");

    /*
    while(katana->openWindow(window))
	{
		katana->drawAll();
	} 

	katana->close();
    */
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
    return 0.f;
}

float KATRender::getCursorY()
{
    return 0.f;
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
