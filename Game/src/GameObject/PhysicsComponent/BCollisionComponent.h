#pragma once
#include "PhysicBullet.h"
#include "GameObject.h"

class BCollisionComponent : public Component 
{
    private:
        btRigidBody* rbody;
    public:
<<<<<<< HEAD
        ~BCollisionComponent(){PhysicBullet::getInstance()->removeRigidBody(rbody);};
=======
        ~BCollisionComponent(){};
>>>>>>> 279a9ad49b978627e52395b561122ef44d5ef381
        BCollisionComponent(GameObject* owner, Manager* manager, float xsize, float ysize, float zsize, float mass) : Component(owner, manager)
        {
            btVector3 position = btVector3(owner->getX(), owner->getY(), owner->getZ());
            btVector3 size = btVector3(xsize, ysize, zsize);
            rbody = PhysicBullet::getInstance()->createRigidBody(position, size, mass);
        }

        void update();
};