#pragma once 


class IGameState
{
public:

    enum stateType {
        MENU,
        PLAY,
        PAUSE,
        END,
        INTRO,
        DIALOGUE,
        NEXTLEVEL
    };

    virtual ~IGameState() {};
    virtual void initState() = 0;
    virtual void update(float dt) = 0;
    virtual void clear() = 0; 
    stateType type;
};