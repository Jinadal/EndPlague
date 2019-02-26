#include <cstddef>
#include "DialogueState.h"
#include <SFML/Window.hpp>
#include "Game.h"
#include "HUD.h"


void DialogueState::initState()
{
    type = IGameState::DIALOGUE;
}
void DialogueState::update(float dt)
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || 
        sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) ||
        sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        Game::getInstance()->setState(IGameState::stateType::PLAY);
    }
}