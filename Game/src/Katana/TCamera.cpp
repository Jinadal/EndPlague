#include "TCamera.h"
#include "TEntity.h"
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL 
TCamera::TCamera()
{
    left=2.f;
    right=2.f;
    top=1.f;
    bot=2.f;
    near=0.1f;
    far=10000.f;
    zoom = 45.0;
    
    projectionMatrix() = glm::perspective(glm::radians(zoom), (float)16 / (float)9, near, far);

}

void TCamera::setCameraParametres(float n,float f)
{
    near = n;
    far = f;
    //else when perspective==false==parallel
    if(perspective)
    {
        //glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT,n,f) FOR THE FUTURE
        projectionMatrix() = glm::perspective(zoom, (float)16 / (float)9, near, far);
        
    }
    else
    {
    
        projectionMatrix() = glm::ortho(1.0f,1.0f,1.0f,1.0f);
    }
}

