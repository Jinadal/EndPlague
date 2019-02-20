#include "HUD.h"

void HUD::update()
{
    spawnsCount = WoodManager::getInstance()->getSpawnsCount();
    life = GameResource::getInstance()->getPlayer()->getComponent<LifeComponent>()->getLife();
    score = ScoreManager::getInstance()->getScore();
    berseck = false;
    terrify = false;
}