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
    //TTransform* scale = (TTransform*)camera->getFather()->getFather()->getEntity();


    translate->identity();
    //scale->identity();
    rotate->identity();

    rotate->rotate(1, 0, 0, 3.14);
    //rotate->rotate(0, 1, 0, 3.14);

    //scale->scale(-1,-1,1);
    translate->translate(-x, y, z);
   
    


   //KATRender::getInstance()->setCamera(-x, y, z, -rx, ry, rz);
}

void KATCamera::setFOV(float fov)
{
    
}