#pragma once
#include "IGameState.h"

//const char* videoPath = "";
const float videoDuration = 3.f; //seg

class IntroState : public IGameState 
{
    private:
        IntroState(){}
        float delta = 0.f;

    public:

    static IntroState* getInstance(){
        static IntroState only_instance;
        return &only_instance;
    }
        

    ~IntroState() {}
    void initState();
    void update(float dt);
    void clear();
};