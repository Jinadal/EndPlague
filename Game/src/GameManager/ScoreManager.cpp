#include "ScoreManager.h"
#include "ScoreComponent.h"
#include "GameObject.h"

ScoreManager* ScoreManager::only_instance = nullptr;

void ScoreManager::createComponent(GameObject* owner, int score)
{
    components.push_back(new ScoreComponent(owner, this, score));
    owner->addComponent(components[components.size()-1]);
}


void ScoreManager::applyScore(int score)
{
    this->score+=score;
}