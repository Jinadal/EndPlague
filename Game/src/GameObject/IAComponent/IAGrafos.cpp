#include "IAGrafos.h"
#include "GameObject.h"
#include "Waypoint.h"
#include "Area.h"
#include "IAComponent.h"
#include "IAManager.h"
#include <cmath>
#include "BPhysicComponent.h"
#include "RenderComponent.h"


bool IA_Graf_Checkarea ::run()
{

   std::vector<Area*> Areas = ((IAManager*)owner->getComponent<IAComponent>()->getManager())->getGPS()->getAreas();
    

    int ai=0; 
    int af=0;
    for (std::size_t i = 0; i< Areas.size(); i++)
    {
        if(Areas[i]->checkinArea(owner->getX(),owner->getY()))
        {
            ai = i;
        }

        if(Areas[i]->checkinArea(main->getX(),main->getY()))
        {

            af = i;
        }

    }

    if(af == ai)
    {
        if(owner->getComponent<IAComponent>()->onRoute){
            owner->getComponent<IAComponent>()->onRoute = false;
           
        }
        
        return false;
    }

   // if(owner->getComponent<IAComponent>()->onRoute)
    //return false;
    owner->getComponent<RenderComponent>()->setTexture((char*)"res/red.bmp");

    return true;
}

bool IA_Graf_LaunchGPS::run()
{
    GPS* gps = ((IAManager*)owner->getComponent<IAComponent>()->getManager())->getGPS();

  owner->getComponent<IAComponent>()->route = gps->getWay(owner->getX(),owner->getY(),main->getX(),main->getY());
    
     owner->getComponent<IAComponent>()->onRoute = true;
    
    return true;
}

bool IA_Graf_CheckRuta::run()
{
    if(owner->getComponent<IAComponent>()->onRoute){
        owner->getComponent<RenderComponent>()->setTexture((char*)"res/yelow.bmp");
        return true;
    }

    return false;
}

bool IA_Graf_FollowRuta::run()
{

std::vector<float> ruta = owner->getComponent<IAComponent>()->route;


std::vector<float>::iterator iter = ruta.begin();

float nextX = *iter;

//ruta.erase(iter);
iter++;

float nextY = *iter;

//ruta.erase(iter);



float dx = nextX - owner->getX();
float dy = nextY - owner->getY();
    
if(fabs(dx) >= fabs(dy)) 
{
    if(dx > 0)
    {
        owner->getComponent<BPhysicComponent>()->moveObject(1,0,0,nextX,nextY);
        owner->getComponent<BPhysicComponent>()->setvMax(3.f);
        

    }else{

        owner->getComponent<BPhysicComponent>()->moveObject(-1,0,0,nextX,nextY);
        owner->getComponent<BPhysicComponent>()->setvMax(3.f);
        
    }

}else{

    if(dy > 0)
    {
        owner->getComponent<BPhysicComponent>()->moveObject(0,1,0,nextX,nextY);
        owner->getComponent<BPhysicComponent>()->setvMax(3.f);
       


    }else{

        owner->getComponent<BPhysicComponent>()->moveObject(0,-1,0,nextX,nextY);
        owner->getComponent<BPhysicComponent>()->setvMax(3.f);
        
    }

}

if(round(fabs(dx)) < .5f &&round(fabs(dy)) < .5f )
{
    int tam = ruta.size();
    if(tam == 2){
        iter++;
        iter--;
    }
     ruta.erase(iter);
    iter--;
     ruta.erase(iter);
      
    iter = ruta.begin();
  owner->getComponent<IAComponent>()->route = ruta;

}


if(ruta.empty()){
    owner->getComponent<IAComponent>()->onRoute = false;
   //BUSCA POR QUE COÑO SE QUEDA PILLADO EN EL ULTIMO PUNTO
}


    return true;
}