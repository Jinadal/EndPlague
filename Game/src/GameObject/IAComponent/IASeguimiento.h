#include "Nodo.h"
#include "GameObject.h"

class CheckX : public Nodo
{
    public:

    CheckX(GameObject* o, GameObject* m){owner = o; main = m;}
    virtual ~CheckX(){}

    bool run() override;
    GameObject * owner;
    GameObject* main;

};
class CheckXwid : public Nodo
{
    public:

    CheckXwid(GameObject* o, GameObject* m){owner = o; main = m;}
    virtual ~CheckXwid(){}

    bool run() override;
    GameObject * owner;
    GameObject* main;

};

class CheckY : public Nodo
{
    public:

    CheckY(GameObject* o , GameObject* m){owner = o; main = m;}
    virtual ~CheckY(){}

    bool run() override;
    GameObject * owner;
    GameObject* main;


};
class CheckYhei : public Nodo
{
    public:

    CheckYhei(GameObject* o, GameObject* m){owner = o; main = m;}
    virtual ~CheckYhei(){}

    bool run() override;
    GameObject * owner;
    GameObject* main;


};