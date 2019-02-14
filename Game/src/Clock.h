#include <chrono>
#include <iostream>
#define FPS 60

class Clock
{
    private:
        std::chrono::duration<double>  elapsedTime; //The elapsed time on a single iteration
        std::chrono::time_point<std::chrono::high_resolution_clock> lastTime; //The elapsed time amounted
        bool toReset = false;
    public:
        Clock();
        float getElapsedTime();
        bool canContinue();


};

Clock::Clock()
{
    toReset = false;
    lastTime = std::chrono::high_resolution_clock::now();
};

float Clock::getElapsedTime()
{

    std::cout<<"Elapsed: "<<elapsedTime.count()<<"\n";
    return elapsedTime.count();
};

bool Clock::canContinue()
{
    if(toReset)
        elapsedTime = lastTime - lastTime;

    std::chrono::time_point<std::chrono::high_resolution_clock> currentTime = std::chrono::high_resolution_clock::now();

    elapsedTime += currentTime - lastTime;

    double minTime = 1.0/FPS;
    if(elapsedTime.count() > minTime)
    {
        std::cout<<"Continue\n";
        toReset = true;
        lastTime = currentTime;
        return true;
    }

    lastTime = currentTime;
    return false;
};