#include <cstddef>
#include "ToNextState.h"
#include <SFML/Window.hpp>
#include "Game.h"
#include "PlayState.h"
#include "LevelLoader.h"
#include "Render.h"
#include "FMenu.h"

void ToNextState::initState()
{
    type = IGameState::TONEXT;
    
    Render::getInstance()->getMenu()->setMenuBackground((char*)"res/sprites/Next.png");
}
void ToNextState::update(float dt)
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        Game::getInstance()->setState(IGameState::stateType::PLAY);
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
    {
        LevelLoader::getInstance()->resetNext();
        Game::getInstance()->setState(IGameState::stateType::MENU);
    }
}