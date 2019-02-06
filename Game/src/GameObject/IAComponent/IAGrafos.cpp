#include "IAGrafos.h"
#include "GameObject.h"
#include "Waypoint.h"
#include "Area.h"
#include "IAComponent.h"
#include "IAManager.h"
#include <cmath>
#include "BPhysicComponent.h"


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
        
        
        return false;
    }
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
    if(owner->getComponent<IAComponent>()->onRoute)return true;

    return false;
}

bool IA_Graf_FollowRuta::run()
{

std::vector<float> ruta = owner->getComponent<IAComponent>()->route;

std::vector<float>::iterator iter = ruta.begin();

float nextX = *iter;

ruta.erase(iter);
iter = ruta.begin();

float nextY = *iter;

ruta.erase(iter);



float dx = nextX - owner->getX();
float dy = nextY - owner->getY();
    
if(fabs(dx) >= fabs(dy)) 
{
    if(dx > 0)
    {
        owner->getComponent<BPhysicComponent>()->moveObject(1,0,0,nextX,nextY);
        owner->getComponent<BPhysicComponent>()->setvMax(5.f);
        

    }else{

        owner->getComponent<BPhysicComponent>()->moveObject(-1,0,0,nextX,nextY);
        owner->getComponent<BPhysicComponent>()->setvMax(5.f);
        
    }

}else{

    if(dy > 0)
    {
        owner->getComponent<BPhysicComponent>()->moveObject(0,1,0,nextX,nextY);
        owner->getComponent<BPhysicComponent>()->setvMax(5.f);
       


    }else{

        owner->getComponent<BPhysicComponent>()->moveObject(0,-1,0,nextX,nextY);
        owner->getComponent<BPhysicComponent>()->setvMax(5.f);
        
    }

}

iter = ruta.begin();
if(iter == ruta.end()) owner->getComponent<IAComponent>()->onRoute = false;



    return true;
}