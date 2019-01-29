#include "Nodo.h"

class GameObject;
class IA_Seg_CheckXIzd : public Nodo
{
    public:

    IA_Seg_CheckXIzd(GameObject* o, GameObject* m){owner = o; main = m;}
    virtual ~IA_Seg_CheckXIzd(){}

    bool run() override;
    GameObject * owner;
    GameObject* main;

};
class IA_Seg_CheckXDer : public Nodo
{
    public:

    IA_Seg_CheckXDer(GameObject* o, GameObject* m){owner = o; main = m;}
    virtual ~IA_Seg_CheckXDer(){}

    bool run() override;
    GameObject * owner;
    GameObject* main;

};

class IA_Seg_CheckYAbj : public Nodo
{
    public:

    IA_Seg_CheckYAbj(GameObject* o , GameObject* m){owner = o; main = m;}
    virtual ~IA_Seg_CheckYAbj(){}

    bool run() override;
    GameObject * owner;
    GameObject* main;


};
class IA_Seg_CheckYArr : public Nodo
{
    public:

    IA_Seg_CheckYArr(GameObject* o, GameObject* m){owner = o; main = m;}
    virtual ~IA_Seg_CheckYArr(){}

    bool run() override;
    GameObject * owner;
    GameObject* main;


};



class IA_Seg_DifX : public Nodo
{
    public:

    IA_Seg_DifX (GameObject* o, GameObject* m){owner = o; main = m;}
    virtual ~IA_Seg_DifX (){}

    bool run() override;
    GameObject * owner;
    GameObject* main;


};
class IA_Seg_DifY : public Nodo
{
    public:

    IA_Seg_DifY (GameObject* o, GameObject* m){owner = o; main = m;}
    virtual ~IA_Seg_DifY (){}

    bool run() override;
    GameObject * owner;
    GameObject* main;


};