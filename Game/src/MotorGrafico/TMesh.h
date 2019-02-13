

#include <iostream>

class TEntity;
class TResource;
class TMesh : public TEntity
{
    private:
        TResource* mesh;
    public:
        TMesh(){}
        ~TMesh(){}

        //Get & Set
        void setMesh(TResource* m){ mesh = m;};
        TResource* getMesh(){ return mesh;};

        void beginDraw(){}
        void endDraw(){}
        
};
