#include "TEntity.h"
#include <GL/glew.h>
#include <glm/ext.hpp>

class TCamera : public TEntity
{
    private:
        //Parallel or perspective; true == persective, false == parallel
        bool perspective:
        float near,far,top,bot,right,left;
    public:
        TCamera();
        ~TCamera();

        void setCameraParametres(float,float,float,float,float,float);
        void setPerspective(){ perspective = true};
        void changeCamera(bool c){ perspective = c};
        void beginDraw();
        void endDraw();

};
