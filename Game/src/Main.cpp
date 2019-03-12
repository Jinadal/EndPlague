#include "Game.h"
#include "LevelLoader.h"
int main(){
    LevelLoader::getInstance()->writeFile();
    Game::getInstance()->run();

    return 0;
}