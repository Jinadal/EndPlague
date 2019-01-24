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
#include "WoodManager.h"
#include "FabricVillage.h"
#include "TestFabric.h"

class PlayState : public IGameState 
{
    private:
    bool loaded;
    static PlayState* only_instance;
    RenderIrrlicht*         render;              
    Fabric*                 fabric;  
    InputManager*           inputmanager;
    SpawnManager*           spawnmanager;
    IAManager*              iamanager;
    BPhysicManager*         bphysicmanager;
    ShootManager*           shootmanager;
    CameraManager*          cameramanager;
    RenderManager*          rendermanager;
    StorageManager*         storagemanager;
    WoodManager*            woodmanager;
    GameResource*           gameresource;

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