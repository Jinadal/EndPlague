#pragma once 


class IGameState
{
public:

    enum stateType {
        MENU,
        PAUSE,
        END
    };

    virtual ~IGameState() {};
    virtual void initState() = 0;
    virtual void update() = 0;
    
    stateType type;

};