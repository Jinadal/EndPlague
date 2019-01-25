#include <cstddef>
#include "PlayState.h"
#include <iostream>
#include <SFML/Window.hpp>
#include "Game.h"
#include "LifeComponent.h"


PlayState* PlayState::only_instance = NULL;
void PlayState::initState()
{
    type = IGameState::PLAY;
    render              = RenderIrrlicht::getInstance();
    renderstatictext    = new RenderStaticText();
    fabric              = new FabricVillage();
    //fabric              = new TestFabric();
    inputmanager        = InputManager::getInstance();
    spawnmanager        = SpawnManager::getInstance();
    iamanager           = IAManager::getInstance();
    bphysicmanager      = BPhysicManager::getInstance();
    shootmanager        = ShootManager::getInstance();
    cameramanager       = CameraManager::getInstance();
    rendermanager       = RenderManager::getInstance();
    storagemanager      = StorageManager::getInstance();
    lifemanager         = LifeManager::getInstance();
    gameresource        = GameResource::getInstance();
    if(!loaded)
    {
        loaded=true;
        fabric->loadLevel();
    }
}
void PlayState::update(float dt)
{

    renderstatictext->updateValues(ScoreManager::getInstacne()->getEnemies(), 
                                    1.f/dt, 
                                    ((LifeComponent*)fabric->getPlayer()->getComponent<LifeComponent>())->getLife(),
                                    ScoreManager::getInstacne()->getScore());

    InputManager::getInstance()->setCursorPosition(render->getCursorX(), render->getCursorY());
    GameResource::getInstance()->updateAll();
    InputManager::getInstance()->updateAll(dt);
    SpawnManager::getInstance()->updateAll(dt);
    IAManager::getInstance()->updateAll(dt);
    BPhysicManager::getInstance()->updateAll(dt);
    ShootManager::getInstance()->updateAll(dt);
    WoodManager::getInstance()->updateAll(dt);
    CameraManager::getInstance()->updateAll(dt);
    LifeManager::getInstance()->updateAll(dt);
    RenderManager::getInstance()->updateAll(dt);
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        Game::getInstance()->setState(IGameState::stateType::PAUSE);
    
    if(IAManager::getInstance()->getPlayer()->getKill())
    {
        clear();
        Game::getInstance()->setState(IGameState::stateType::END);
    }
}

void PlayState::clear(){
    //delete inputmanager;
    delete spawnmanager;
    delete iamanager;
    delete bphysicmanager;
    delete shootmanager;
    delete cameramanager;
    delete rendermanager;
    delete gameresource;
    delete renderstatictext;




    delete fabric;

    loaded=false;

}