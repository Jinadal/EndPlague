#include "IAFire.h"
#include "BPhysicManager.h"
#include "FabricVillage.h"
#include "GameObject.h"
#include "IAComponent.h"
#include "Waypoint.h"
#include "IAManager.h"
#include "WoodComponent.h"
#include "Fabric.h"
#include "BucketComponent.h"

bool IA_Fire_seefire::run()
{
  
  std::vector<GameObject*> spawns = BuildtRecord::getInstance()->getSpawns();

  for(std::vector<GameObject*>::iterator iter = spawns.begin(); iter!=spawns.end(); iter++)
  {
    if((*iter)->getComponent<WoodComponent>()->getBurning())
    {
        owner->getComponent<IAComponent>()->spawnOnFire = *iter;
        return true;
    }
  }
  return false;
}


bool IA_Fire_searchWell::run()
{
  
  std::vector<GameObject*> wells = BuildtRecord::getInstance()->getPozos();
  float dfinal = 1000000;
  GameObject* well;
  for(std::vector<GameObject*>::iterator iter = wells.begin(); iter!=wells.end(); iter++)
  {
    float d = round(sqrt(pow((*iter)->getX() - owner->getX(),2) + pow((*iter)->getY() - owner->getY(),2)));
    if(d<dfinal)
    {
       dfinal = d;
       well = *iter;
    }
  }

  owner->getComponent<IAComponent>()->pozoObjetivo = well;
  return true;
}



bool IA_Fire_GPStoSpawn::run()
{
    GPS* gps = ((IAManager*)owner->getComponent<IAComponent>()->getManager())->getGPS();
    GameObject* spawn = owner->getComponent<IAComponent>()->spawnOnFire;

  owner->getComponent<IAComponent>()->route = gps->getWay(owner->getX(),owner->getY(),spawn->getX(),spawn->getY());
    
     owner->getComponent<IAComponent>()->onRoute = true;
    
    return true;
}

bool IA_Fire_GPStoWell::run()
{
    GPS* gps = ((IAManager*)owner->getComponent<IAComponent>()->getManager())->getGPS();
    GameObject* well = owner->getComponent<IAComponent>()->pozoObjetivo;

  owner->getComponent<IAComponent>()->route = gps->getWay(owner->getX(),owner->getY(),well->getX(),well->getY());
    
     owner->getComponent<IAComponent>()->onRoute = true;
    
    return true;
}

bool IA_Fire_haveWater::run()
{
  if(owner->getComponent<BucketComponent>() && owner->getComponent<BucketComponent>()->getWater())
    return false;
    
  return true;
}