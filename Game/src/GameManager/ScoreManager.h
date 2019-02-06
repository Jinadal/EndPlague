#pragma once
#include "Manager.h"

class GameObject;
class ScoreManager : public Manager
{
    private:
        static ScoreManager* only_instance;
        ScoreManager():Manager(){score = 0.f;}
        int score;
    
    public:
        ~ScoreManager(){only_instance = NULL;}
        static ScoreManager* getInstance()
        {
            if (!only_instance) {
                only_instance = new ScoreManager();
            }
            
            return only_instance;
        }

        void createComponent(GameObject* owner, int score);
        void updateAll(float dt){}
        void applyScore(int score);
        int getScore(){return score;};
        int getEnemies(){return static_cast<int>(components.size());};
};