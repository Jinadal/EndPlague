#include "Nodo.h"

class GameObject;
class IA_Graf_Checkarea : public Nodo
{
    public:

    IA_Graf_Checkarea(GameObject* o, GameObject* m){owner = o;main = m;}
    virtual ~IA_Graf_Checkarea(){}

    bool run() override;
    GameObject * owner;
    GameObject * main;
    

};

class IA_Graf_LaunchGPS : public Nodo
{
    public:

    IA_Graf_LaunchGPS(GameObject* o, GameObject* m){owner = o;main = m;}
    virtual ~IA_Graf_LaunchGPS(){}

    bool run() override;
    GameObject * owner;
    GameObject * main;
    

};

class IA_Graf_CheckRuta : public Nodo
{
    public:

    IA_Graf_CheckRuta(GameObject* o){owner = o;}
    virtual ~IA_Graf_CheckRuta(){}

    bool run() override;
    GameObject * owner;    

};

class IA_Graf_FollowRuta : public Nodo
{
    public:

    IA_Graf_FollowRuta(GameObject* o){owner = o;}
    virtual ~IA_Graf_FollowRuta(){}

    bool run() override;
    GameObject * owner;    

};
