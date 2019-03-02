#pragma once
#include "FCamera.h"
#include "RenderIrrlicht.h"
#include "Component.h"
#include "GameObject.h"

class GameObject;
class CameraComponent : public Component{
    private:
        FCamera* node;
        float x, y, z;
        float rz;
        float zoom = 1.f;
    public:
        CameraComponent(GameObject* parent, Manager* m) : Component(parent, m)
        {
            node = RenderIrrlicht::getInstance()->createCamera();
            x = parent->getX();
            y = parent->getY();
            z = parent->getZ();
            rz = 0.f;
        }

        ~CameraComponent()
        {
            delete node;
        }

        void update(float dt);
        void setFOV(float fov);
        void setZoom(float dt);

};