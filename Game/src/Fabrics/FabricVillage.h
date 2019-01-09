#include "Fabric.h"
#include "InputManager.h"
#include "SpawnManager.h"
#include "IAManager.h"
#include "BPhysicManager.h"
#include "ShootManager.h"
#include "CameraManager.h"
#include "RenderManager.h"
#include "StorageManager.h"
#include "GameResource.h"


class FabricVillage : public Fabric{
    private:
        
        
    public:
        FabricVillage():Fabric(){}
        ~FabricVillage(){}

        void loadLevel();
};