#include <cstddef>
#include "NextLevelState.h"
#include <SFML/Window.hpp>
#include "Game.h"


void NextLevelState::initState()
{
    type = IGameState::NEXTLEVEL;
}
void NextLevelState::update(float dt)
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        Game::getInstance()->setState(IGameState::stateType::PLAY);
    }
    
}