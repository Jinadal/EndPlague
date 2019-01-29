#include "Area.h"

bool Area::checkinArea(float pjx, float pjy)
{
    bool inside = false;
    if (pjx>=sx && pjx<=ix && pjy>=sy && pjy<=iy)
        inside = true;

    return inside;
}

void Area::addWaypoint(Waypoint* w)
{
    waypoints.push_back(w);
}