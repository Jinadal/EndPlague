#include "Nodo.h"

class GameObject;
class IA_Seg_CheckXIzd : public Nodo
{
    public:

    IA_Seg_CheckXIzd(GameObject* o, float objetiveX){owner = o; XtoGo= objetiveX;}
    virtual ~IA_Seg_CheckXIzd(){}

    bool run() override;
    GameObject * owner;
    float XtoGo;

};
class IA_Seg_CheckXDer : public Nodo
{
    public:

    IA_Seg_CheckXDer(GameObject* o, float objetiveX){owner = o; XtoGo= objetiveX;}
    virtual ~IA_Seg_CheckXDer(){}

    bool run() override;
    GameObject * owner;
    float XtoGo;


};

class IA_Seg_CheckYAbj : public Nodo
{
    public:

    IA_Seg_CheckYAbj(GameObject* o , float objetiveY){owner = o; YtoGo= objetiveY;}
    virtual ~IA_Seg_CheckYAbj(){}

    bool run() override;
    GameObject * owner;
    float YtoGo;


};
class IA_Seg_CheckYArr : public Nodo
{
    public:

    IA_Seg_CheckYArr(GameObject* o, float objetiveY){owner = o; YtoGo= objetiveY;}
    virtual ~IA_Seg_CheckYArr(){}

    bool run() override;
    GameObject * owner;
    float YtoGo;


};



class IA_Seg_DifX : public Nodo
{
    public:

    IA_Seg_DifX (GameObject* o, float objetiveX, float objetiveY){owner = o;XtoGo = objetiveX; YtoGo = objetiveY;}
    virtual ~IA_Seg_DifX (){}

    bool run() override;
    GameObject * owner;
    float XtoGo;
    float YtoGo;

};
class IA_Seg_DifY : public Nodo
{
    public:

    IA_Seg_DifY (GameObject* o, float objetiveX, float objetiveY){owner = o;XtoGo = objetiveX; YtoGo = objetiveY;}
    virtual ~IA_Seg_DifY (){}

    bool run() override;
    GameObject * owner;
    float XtoGo;
    float YtoGo;


};