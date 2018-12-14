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
        }

        void update();
        static bool callbackFunc(btManifoldPoint& cp, const btCollisionObjectWrapper* obj1, int id1, int index1, const btCollisionObjectWrapper* obj2, int id2, int index2);

};