#pragma once

class FMenu
{
    protected:
        FMenu(){};
    public:  
        virtual ~FMenu(){};
        virtual void setMenuBackground() = 0;
        virtual void clearBackground() = 0;
        virtual void update() = 0;
};