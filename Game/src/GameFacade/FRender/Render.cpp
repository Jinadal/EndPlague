#include "Render.h"
#include "LOTRender.h"
#include "IRRRender.h"
#include "GameValues.h"

Render::Render(){
    if(gv::RENDER_ENGINE)
    {
        render = IRRRender::getInstance();
    }else
    {
        render = LOTRender::getInstance();
    }
}

void Render::drawAll(){render->drawAll();}

bool Render::run(){return render->run();}

void Render::drop(){render->drop();}

float Render::getCursorX(){return render->getCursorX();}
float Render::getCursorY(){return render->getCursorY();}

FMesh* Render::createMesh(char* s){return render->createMesh(s);}
FCamera* Render::createCamera(){return render->createCamera();}
FHUD* Render::createHUD(){return render->createHUD();}
FMenu* Render::getMenu(){return render->getMenu();}