#pragma once
#include "FCamera.h"

class KATCamera : public FCamera
{
    public:
        KATCamera(){};
        ~KATCamera(){};
        void update(float x, float y, float z, float rx, float ry, float rz);
        void setFOV(float fov);
};