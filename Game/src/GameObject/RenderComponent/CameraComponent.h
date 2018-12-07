#pragma once
#include "CameraNode.h"
#include "Component.h"
#include "GameObject.h"


class CameraComponent : public Component{
    private:
        CameraNode* node;
        float x, y, z, dMAX=50.f, v=1000.f;

    public:
        CameraComponent(GameObject* parent, Manager* m) : Component(parent, m)
        {
            node = new CameraNode();
            x = parent->getX();
            y = parent->getY();
            z = parent->getZ();
        }

        ~CameraComponent()
        {
            delete node;
        }

        void update(float dt);
        void setFOV(f32 fov);

};