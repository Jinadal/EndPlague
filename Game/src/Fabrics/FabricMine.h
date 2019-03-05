#include "Fabric.h"

class FabricMine : public Fabric{
    private:
        
        
    public:
        FabricMine():Fabric(){}
        ~FabricMine(){}

        void loadLevel();
        void well(float x, float y, float rz, bool type);
        void spawn(float x, float y, float rz, bool type);


};