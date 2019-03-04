#include "TCamera.h"
#include "TEntity.h"
void TCamera::setCameraParametres(float n,float f,float t,float b,float r,float l)
{
    near = n;
    far = f;
    top = t;
    bot = b;
    right = r;
    left = l;

    //else when perspective==false==parallel
    if(perspective)
    {
        //glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT,n,f) FOR THE FUTURE
        projectionMatrix() = glm::perspective(0.0f,0.f,n,f);
    }
    else
    {
    
        projectionMatrix() = glm::ortho(l,r,b,t);
    }
}