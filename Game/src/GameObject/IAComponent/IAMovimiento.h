#include "Nodo.h"

class GameObject;
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

    MoverArriba(GameObject * o, float objetiveX, float objetiveY){owner = o;XtoGo = objetiveX; YtoGo = objetiveY;}
    virtual ~MoverArriba(){}

    bool run() override;

GameObject * owner;
float XtoGo;
float YtoGo;

};
class MoverIzda : public Nodo
{
    
    public:

    MoverIzda(GameObject * o, float objetiveX, float objetiveY){owner = o;XtoGo = objetiveX; YtoGo = objetiveY;}
    virtual ~MoverIzda(){}

    bool run() override;

GameObject * owner;
float XtoGo;
float YtoGo;
};

class MoverDcha : public Nodo
{
    
    public:

    MoverDcha(GameObject * o, float objetiveX, float objetiveY){owner = o;XtoGo = objetiveX; YtoGo = objetiveY;}
    virtual ~MoverDcha(){}

    bool run() override;

GameObject * owner;
float XtoGo;
float YtoGo;
};

class MoverAbajo : public Nodo
{
    
    public:

    MoverAbajo(GameObject * o, float objetiveX, float objetiveY){owner = o;XtoGo = objetiveX; YtoGo = objetiveY;}
    virtual ~MoverAbajo(){}

    bool run() override;

GameObject * owner;
float XtoGo;
float YtoGo;
};