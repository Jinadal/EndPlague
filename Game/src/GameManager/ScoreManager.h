#pragma once
#include "Manager.h"
class Manager;
class GameObject;
class ScoreManager : public Manager
{
    private:
        static ScoreManager* only_instance;
        ScoreManager():Manager(){score = 0.f;}
        int score;
    
    public:
        static ScoreManager* getInstance()
        {
            if (only_instance==NULL) {
                only_instance = new ScoreManager();
            }
            
            return only_instance;
        }
        virtual ~ScoreManager(){}

        void createComponent(GameObject* owner, int score);
        void updateAll(float dt){}
        void applyScore(int score);
        int getScore(){return score;};
        int getEnemies(){return static_cast<int>(components.size());};
};