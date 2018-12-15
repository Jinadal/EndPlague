#pragma once
#include "RenderIrrlicht.h"

class RenderIrrlicht;
class CameraNode{
    private:
        ICameraSceneNode* node;
    public:
        CameraNode()
        {
            node = RenderIrrlicht::getInstance()->getSMgr()->addCameraSceneNode(0, vector3df(0,0,0), vector3df(0,0,0));
            node->setAutomaticCulling(EAC_OFF);
        }

        ~CameraNode()
        {
            delete node;
        }

        void update(float x, float y, float z, float rx, float ry, float rz);
        void setFOV(float fov);

};
