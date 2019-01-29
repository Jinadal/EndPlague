#include "IAGrafos.h"
#include "GameObject.h"
#include "Waypoint.h"
#include "IAComponent.h"


bool IA_Graf_SetAWaypoint::run()
{

    Waypoint* way = owner->getComponent<IAComponent>()->grafo->getNearestWaypoint(owner->getX(),owner->getY());

    owner->getComponent<IAComponent>()->waypoint = way;
    owner->getComponent<IAComponent>()->hasWaypoint = true;
    return true;
}