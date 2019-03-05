#include "LOTRender.h"
#include "LOTMesh.h"
#include "LOTCamera.h"
#include "LOTHUD.h"
#include "LOTMenu.h"

void LOTRender::drawAll()
{

}

bool LOTRender::run()
{
    return true;
}

void LOTRender::drop()
{

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
