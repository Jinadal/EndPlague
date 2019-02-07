#include "Nodo.h"
#include "GameObject.h"


class Pared : public Nodo
{
    
    public:

    Pared(GameObject* o){owner = o;}
    virtual ~Pared(){}

    bool run() override;
GameObject * owner;

};

class MoverArriba : public Nodo
{
    
    public:

    MoverArriba(GameObject * o, GameObject * m){owner = o; main = m;}
    virtual ~MoverArriba(){}

    bool run() override;

GameObject * owner;
GameObject * main;

};
class MoverIzda : public Nodo
{
    
    public:

    MoverIzda(GameObject * o, GameObject * m){owner = o;main = m;}
    virtual ~MoverIzda(){}

    bool run() override;

GameObject * owner;
GameObject * main;
};

class MoverDcha : public Nodo
{
    
    public:

    MoverDcha(GameObject * o, GameObject * m){owner = o; main = m;}
    virtual ~MoverDcha(){}

    bool run() override;

GameObject * owner;
GameObject * main;
};

class MoverAbajo : public Nodo
{
    
    public:

    MoverAbajo(GameObject * o, GameObject * m){owner = o; main = m;}
    virtual ~MoverAbajo(){}

    bool run() override;

GameObject * owner;
GameObject * main;
};