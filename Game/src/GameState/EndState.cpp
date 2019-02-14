#include <cstddef>
#include "EndState.h"
#include "Game.h"
#include <SFML/Window.hpp>
#include "ScoreManager.h"
#include <iostream>

void EndState::update(float dt)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        Game::getInstance()->setState(IGameState::stateType::MENU);
    
}

void EndState::initState(){
    std::cout<<"Puntuacion final: "<<ScoreManager::getInstance()->resetScore()<<"\n";
    type = IGameState::END; 
};