#include "Fabric.h"

class TestFabric : public Fabric{
    public:
        TestFabric():Fabric(){}
        ~TestFabric(){}

        void loadLevel();
};