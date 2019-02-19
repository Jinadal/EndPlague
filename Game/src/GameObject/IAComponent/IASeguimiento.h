#include "Nodo.h"
#include "GameObject.h"

class IA_Seg_ToPlayer : public Nodo
{
    public:

    IA_Seg_ToPlayer(GameObject* o, GameObject* m){owner = o; main = m;}
    virtual ~IA_Seg_ToPlayer(){}

    bool run() override;
    GameObject * owner;
    GameObject* main;

};
