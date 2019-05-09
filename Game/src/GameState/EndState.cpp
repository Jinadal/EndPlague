#include <cstddef>
#include "EndState.h"
#include "Render.h"
#include "FMenu.h"
#include "Game.h"
#include <SFML/Window.hpp>
#include "ScoreManager.h"
#include <iostream>
#include "HUD.h"
#include "SoundSystem.h"

void EndState::update(float dt)
{
    Render::getInstance()->getMenu()->update();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
        SoundSystem::getInstance()->Init();
        clear();
        Game::getInstance()->setState(IGameState::stateType::MENU);
    }  
}

void EndState::initState(){

    if(ScoreManager::getInstance()->getWin())
    {
        Render::getInstance()->getMenu()->setMenuBackground((char*)"res/sprites/Win.png");
    }else
    {
        Render::getInstance()->getMenu()->setMenuBackground((char*)"res/sprites/Loose.png");
    }
    //std::cout<<"Puntuacion final: "<<HUD::getInstance()->getScore()<<"\n";
    type = IGameState::END; 
};


void EndState::clear()
{
    Render::getInstance()->getMenu()->clearBackground();
}