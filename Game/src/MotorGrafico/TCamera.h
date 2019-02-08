#include <GL/glew.h>
#include "TEntity.h"

class TEntity;
class TCamera : public TEntity
{
    private:
        //Parallel or perspective; true == persective, false == parallel
        bool perspective = false;
        float near = 1.0f, far = 1.0f, top = 1.0f, bot = 1.0f, right = 1.0f, left = 1.0f;
    public:
        TCamera(){}
        ~TCamera(){}

        //Get & Set
        void setCameraParametres(float n,float f,float t,float b,float r,float l);
        void setPerspective(){ perspective = true;};
        
        void changeCamera(bool c){ perspective = c;};
        
        void beginDraw();
        void endDraw();

};
