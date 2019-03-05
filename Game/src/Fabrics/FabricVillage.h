#include "Fabric.h"
#include <vector>

class FabricVillage : public Fabric{
    private:
        
    public:
        FabricVillage():Fabric(){}
        ~FabricVillage(){}
        void spawn(float x, float y, float rz, bool type);
        void well(float x, float y, float rz, bool type);
        void loadLevel();
};

