#include <vector>
class Waypoint;

class Area
{
    private:
    std::vector<Waypoint*> waypoints;
    float sx,sy,ix,iy;

    public:
    Area(float supx, float supy, float infx, float infy){sx=supx;sy=supy;ix=infx;iy=infy;}
    virtual ~Area(){}

    bool checkinArea(float pjx, float pjy);
    const 6std::vector<Waypoint*>& getWaypoints(){ return waypoints;}

    void addWaypoint(Waypoint* w);
    
};