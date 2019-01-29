#include "TEntity.h"
#include <GL/glew.h>

class TCamera : public TEntity
{
    private:
        //Parallel or perspective; true == persective, false == parallel
        bool perspective:
        float near, far, top, bot, right, left;
    public:
        TCamera();
        ~TCamera();

        //Get & Set
        void setCameraParametres(float n,float f,float t,float b,float r,float l);
        void setPerspective(){ perspective = true;};
        
        void changeCamera(bool c){ perspective = c;};
        
        void beginDraw();
        void endDraw();

};
