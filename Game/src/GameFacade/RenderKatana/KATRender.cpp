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

	katana->createNodeCamera(scene, glm::vec3(100,0,50),glm::vec3(0,0,0),0.01f,100.0f);
	
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


void KATRender::setCamera(float x,float y,float z,float rx,float ry,float rz)
{
    katana->calculateCamera(glm::vec3(x, y, z),glm::vec3(rx, ry, rz));
}
