#include "IAFire.h"
#include "BPhysicManager.h"
#include "FabricVillage.h"
#include "GameObject.h"
#include "IAComponent.h"
#include "Waypoint.h"
#include "IAManager.h"
#include "WoodComponent.h"
#include "WoodManager.h"
#include "Fabric.h"
#include "BucketComponent.h"
#include "WellManager.h"
#include "WellComponent.h"



bool IA_Fire_seefire::run()
{
  
  std::vector<Component*> spawns = WoodManager::getInstance()->getSpawns();

  for(std::vector<Component*>::iterator iter = spawns.begin(); iter!=spawns.end(); iter++)
  {
      
    if(((WoodComponent*) (*iter))->getBurning())
    {
        owner->getComponent<IAComponent>()->spawnOnFire = (*iter)->getGameObject();
        return true;
    }
  }
  return false;
}


bool IA_Fire_searchWell::run()
{
  
  std::vector<Component*> wells = WellManager::getInstance()->getWells();
  float dfinal = 1000000;
  GameObject* well;
  for(std::vector<Component*>::iterator iter = wells.begin(); iter!=wells.end(); iter++)
  {
    GameObject* obj = ((WellComponent*)(*iter))->getGameObject();
    float d = round(sqrt(pow(obj->getX() - owner->getX(),2) + pow(obj->getY() - owner->getY(),2)));
    if(d<dfinal)
    {
       dfinal = d;
       well = obj;
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