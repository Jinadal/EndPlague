#include <cstddef>
#include "PlayState.h"
#include <SFML/Window.hpp>
#include "Game.h"
#include "InputManager.h"
#include "IAManager.h"
#include "SpawnManager.h"
#include "GameObject.h"
#include "GameManager.h"
#include "ScoreManager.h"
#include "LevelLoader.h"
#include "SpecificSoundEvent.h"


#include <iostream>

void PlayState::initState()
{
    type = IGameState::PLAY;

    if(!loaded)
    {
        loaded=true;
        LevelLoader::getInstance()->loadLevel();
        GameManager::getInstance()->initAll();
       
    }
    
    AmbientSoundEvent* s = new AmbientSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("ambiente"));
    s->start();
    SoundSystem::getInstance()->saveEvent(s,"ambiente");

   

} 


void PlayState::update(float dt)
{
    GameManager::getInstance()->updateAll(dt);
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        Game::getInstance()->setState(IGameState::stateType::PAUSE);


    if(IAManager::getInstance()->getPlayer() && IAManager::getInstance()->getPlayer()->getKill())
    {
        clear();
        LevelLoader::getInstance()->resetNext();
        Game::getInstance()->setState(IGameState::stateType::END);
    }else if(SpawnManager::getInstance()->getNumSpawns()<=-1)
    {
        clear();
        if(!LevelLoader::getInstance()->hasNext())
        {
            ScoreManager::getInstance()->setWin();
            Game::getInstance()->setState(IGameState::stateType::END);
        }else{

            Game::getInstance()->setState(IGameState::stateType::TONEXT);
        }
    }
}


void PlayState::clear(){
    GameManager::getInstance()->clear();
    loaded=false;
}