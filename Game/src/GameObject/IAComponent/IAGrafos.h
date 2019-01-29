#include "Nodo.h"

class GameObject;
class IA_Graf_SetAWaypoint : public Nodo
{
    public:

    IA_Graf_SetAWaypoint(GameObject* o){owner = o;}
    virtual ~IA_Graf_SetAWaypoint(){}

    bool run() override;
    GameObject * owner;
    

};