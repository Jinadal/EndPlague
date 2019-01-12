#pragma once 


class IGameState
{
public:

    enum stateType {
        MENU,
        PLAY,
        PAUSE,
        END
    };

    virtual ~IGameState() {};
    virtual void initState() = 0;
    virtual void update(float dt) = 0;
    
    stateType type;

};