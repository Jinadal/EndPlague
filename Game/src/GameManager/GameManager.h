#include "InputManager.h"
#include "SpawnManager.h"
#include "IAManager.h"
#include "BPhysicManager.h"
#include "ShootManager.h"
#include "CameraManager.h"
#include "RenderManager.h"
#include "GameResource.h"
#include "StorageManager.h"

class GameManager
{
    private:
        InputManager*           inputmanager        = InputManager::getInstance();
        SpawnManager*           spawnmanager        = SpawnManager::getInstance();
        IAManager*              iamanager           = IAManager::getInstance();
        BPhysicManager*         bphysicmanager      = BPhysicManager::getInstance();
        ShootManager*           shootmanager        = ShootManager::getInstance();
        CameraManager*          cameramanager       = CameraManager::getInstance();
        RenderManager*          rendermanager       = RenderManager::getInstance();
        StorageManager*         storagemanager      = StorageManager::getInstance();
        GameResource*           gameresource        = GameResource::getInstance();

    public:
        GameManager(){}
        ~GameManager();

        void update(float dt);
};