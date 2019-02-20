#pragma once
#include "CameraNode.h"
#include "Component.h"
#include "GameObject.h"

const float MIN_ZOOM = .8f;
const float MAX_ZOOM = 1.2f;

class GameObject;
class CameraComponent : public Component{
    private:
        CameraNode* node;
        float x, y, z, dMAX=50.f, v=10.f;
        float rz;
        float zoom = 1.f;
    public:
        CameraComponent(GameObject* parent, Manager* m) : Component(parent, m)
        {
            node = new CameraNode();
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
        void setFOV(f32 fov);
        void setZoom(float dt);

};