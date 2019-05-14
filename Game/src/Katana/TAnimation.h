#include <iostream>
#include "../../lib/GL/glew.h"
#include "TEntity.h"
#include "TResourceAnimation.h"

class TResourceAnimation;
class TAnimation : public TEntity
{
    private:
        TResourceAnimation* animation;
    public:
        TAnimation(){}
        ~TAnimation(){}

        //Get & Set
       // void setAnimation(TAnimation* a){ animation = a;};
        //TResourceAnimation* getAnimation(){ return animation;};

        void beginDraw();
        void endDraw(){}
        
};
