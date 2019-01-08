#pragma once
#include "PhysicBullet.h"
#include "GameObject.h"

class BTerrainComponent : public Component 
{
    private:
        btRigidBody* rbody;
    public:
        BTerrainComponent(GameObject* owner, Manager* manager, char* mesh);
        ~BTerrainComponent(){PhysicBullet::getInstance()->removeRigidBody(rbody);}
};