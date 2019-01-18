#pragma once
#include "IGameState.h"
#include "InputManager.h"
#include "SpawnManager.h"
#include "IAManager.h"
#include "BPhysicManager.h"
#include "ShootManager.h"
#include "CameraManager.h"
#include "RenderManager.h"
#include "RenderIrrlicht.h"
#include "GameResource.h"
#include "StorageManager.h"
#include "FabricVillage.h"

class PlayState : public IGameState 
{
    private:
    bool loaded;
    static PlayState* only_instance;
    RenderIrrlicht*         render;              
    FabricVillage*          fabric;  
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
    virtual void initState();
    virtual void update(float dt);
    virtual void clear();
};