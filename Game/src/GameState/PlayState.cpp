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


void PlayState::initState()
{
    type = IGameState::PLAY;

    if(!loaded)
    {
        loaded=true;

        if(LevelLoader::getInstance()->hasNext())
        {
            LevelLoader::getInstance()->loadLevel();
        }else
        {
            Game::getInstance()->setState(IGameState::stateType::END);            
        }

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
        Game::getInstance()->setState(IGameState::stateType::END);
    }else if(SpawnManager::getInstance()->getNumSpawns()<=0)
    {
        if(!LevelLoader::getInstance()->hasNext())
            ScoreManager::getInstance()->setWin();

        clear();
        initState();
    }
}


void PlayState::clear(){
    GameManager::getInstance()->clear();
    level++;
    loaded=false;

}