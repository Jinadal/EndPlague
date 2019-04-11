#include "KATCamera.h"
#include "KATRender.h"
#include "TNode.h"
#include "TCamera.h"
#include <iostream>
#include <cmath>


void KATCamera::setCamera(TNode* n){
    camera = n; 

}


void KATCamera::update(float x, float y, float z, float rx, float ry, float rz)
{
    TTransform* translate = (TTransform*)camera->getFather()->getEntity();
    TTransform* rotate = (TTransform*)camera->getFather()->getFather()->getFather()->getEntity();

    translate->identity();
    rotate->identity();

    float dz = z - rz;
    float dy = y - ry;

    rotate->rotate(0, 0, 1, 3.1416);
    rotate->rotate(1, 0, 0, 3.1416);
    rotate->rotate(1, 0, 0, atan(dy/dz));
    translate->translate(-x, y, z);
}

void KATCamera::setFOV(float fov)
{
    
}