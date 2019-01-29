#include "IAGrafos.h"


bool IA_Graf_SetAWaypoint::run()
{

    Waypoint* way = owner->getComponent<IAComponent>()->grafo->getNearestWaypoint(owner->getX(),owner->getY());

    owner->getComponent<IAComponent>()->waypoint = way;
    owner->getComponent<IAComponent>()->hasWaypoint = true;
    return true;
}