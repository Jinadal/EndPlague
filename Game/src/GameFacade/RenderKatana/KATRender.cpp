#include "KATRender.h"
#include "KATMesh.h"
#include "KATCamera.h"
#include "KATHUD.h"
#include "KATMenu.h"


KATRender::KATRender()
{
   
}

void KATRender::drawAll()
{

}

bool KATRender::run()
{
    return true;
}

void KATRender::drop()
{

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
    return new KATMesh();
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
