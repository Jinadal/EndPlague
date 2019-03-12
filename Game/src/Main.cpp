#include "Game.h"
#include "Game.h"
#include "LevelLoader.h"
int main(){
    Game::getInstance()->run();
  // LevelLoader::getInstance()->loadNext();
  // LevelLoader::getInstance()->writeFile();

    return 0;
}