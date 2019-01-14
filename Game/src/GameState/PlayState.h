#pragma once
#include "IGameState.h"
#include "InputManager.h"
#include "SpawnManager.h"
#include "IAManager.h"
#include "BPhysicManager.h"
#include "ShootManager.h"
#include "CameraManager.h"
#include "RenderManager.h"
#include "GameResource.h"
#include "StorageManager.h"

class PlayState : public IGameState 
{
    private:
    static PlayState* only_instance;
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

    static PlayState *getInstance(){
        if(only_instance == NULL)
            only_instance = new PlayState();
            
        return only_instance;
    };


    virtual ~PlayState() {}
    virtual void initState(){ type = IGameState::PLAY; };
    virtual void update(float dt);
    virtual void clear();
};