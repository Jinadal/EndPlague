#include "Nodo.h"
#include "GameObject.h"


class IA_Plan_InSight : public Nodo
{
    public:

    IA_Plan_InSight(GameObject* o, GameObject* m){owner = o; main = m;}
    virtual ~IA_Plan_InSight(){}

    bool run() override;
    GameObject * owner;
    GameObject* main;

};

class IA_Plan_DidICollide : public Nodo
{

    public:

    IA_Plan_DidICollide (GameObject* o){owner = o;}
    virtual ~IA_Plan_DidICollide(){}

    bool run() override;
    GameObject * owner;

};

class IA_Plan_ChangeDirection : public Nodo
{

    public:

    IA_Plan_ChangeDirection (GameObject* o){owner = o;}
    virtual ~IA_Plan_ChangeDirection(){}

    bool run() override;
    GameObject * owner;

};

class IA_Plan_HaveWaypoint : public Nodo
{

    public:

    IA_Plan_HaveWaypoint(GameObject* o){owner = o;}
    virtual ~IA_Plan_HaveWaypoint(){}

    bool run() override;
    GameObject * owner;

};