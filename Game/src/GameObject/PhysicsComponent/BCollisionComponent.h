#pragma once
#include "PhysicBullet.h"
#include "GameObject.h"

class BCollisionComponent : public Component 
{
    private:
        btRigidBody* rbody;
    public:
        ~BCollisionComponent(){PhysicBullet::getInstance()->removeRigidBody(rbody);};
        BCollisionComponent(GameObject* owner, Manager* manager, float xsize, float ysize, float zsize, float mass) : Component(owner, manager)
        {
            btVector3 position = btVector3(owner->getX(), owner->getY(), owner->getZ());
            btVector3 size = btVector3(xsize, ysize, zsize);
            rbody = PhysicBullet::getInstance()->createRigidBody(position, size, mass);
            rbody->setUserPointer((void *)(gameObject));
        }

        void update();
};