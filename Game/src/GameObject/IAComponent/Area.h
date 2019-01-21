#include "Waypoint.h"
class Area
{
    private:
    Waypoint* waypoint;
    float sx,sy,ix,iy;

    public:
    Area(Waypoint* asociado, float supx, float supy, float infx, float infy){waypoint=asociado;sx=supx;sy=supy;ix=infx;iy=infy;}
    ~Area(){}

    bool checkinArea(float pjx, float pjy);
    Waypoint* getWaypoint(){ return waypoint;}
};