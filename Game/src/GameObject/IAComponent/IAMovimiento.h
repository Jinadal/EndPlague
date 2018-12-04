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

    MoverArriba(GameObject * o){owner = o;}
    virtual ~MoverArriba(){}

    bool run() override;

GameObject * owner;
};
class MoverIzda : public Nodo
{
    
    public:

    MoverIzda(GameObject * o){owner = o;}
    virtual ~MoverIzda(){}

    bool run() override;

GameObject * owner;
};

class MoverDcha : public Nodo
{
    
    public:

    MoverDcha(GameObject * o){owner = o;}
    virtual ~MoverDcha(){}

    bool run() override;

GameObject * owner;
};