#include "Game.h"
#include "LevelLoader.h"
#include "SpecificSoundEvent.h"
#include <SFML/Window.hpp>
int main(){



    
    LevelLoader::getInstance()->writeFile();
    Game::getInstance()->run();

    return 0;
}