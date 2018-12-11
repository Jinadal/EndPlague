#include "CameraNode.h"

void CameraNode::update(float x, float y, float z, float rx, float ry, float rz)
{
    node->setPosition(vector3d<f32>(x, y, z));
    node->setTarget(vector3d<f32>(rx, ry, rz));
}

void CameraNode::setFOV(float fov)
{
    node->setFOV(fov);
}