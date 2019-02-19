#include "Fabric.h"
#include <vector>

struct Position
{
    float _x;
    float _y;
    float _rz;
    bool type;
};

class FabricVillage : public Fabric{
    private:
        
    public:
        FabricVillage():Fabric(){}
        ~FabricVillage(){}
        void spawn(float x, float y, float rz, bool type);
        void well(float x, float y, float rz, bool type);
        void loadLevel();
};

