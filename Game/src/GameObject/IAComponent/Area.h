#include "Waypoint.h"
class Area
{
    private:
    Waypoint* waypoint;
    float sx,sy,ix,iy;

    public:
    Area(float supx, float supy, float infx, float infy){waypoint=new Waypoint((infx-supx)/2,(infy-supy)/2);sx=supx;sy=supy;ix=infx;iy=infy;}
    virtual ~Area(){delete waypoint;}

    bool checkinArea(float pjx, float pjy);
    Waypoint* getWaypoint(){ return waypoint;}
};