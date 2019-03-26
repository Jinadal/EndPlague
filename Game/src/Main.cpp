#include "Game.h"
#include "SpecificSoundEvent.h"
#include <SFML/Window.hpp>
int main(){
    Game::getInstance()->run();

    return 0;
}