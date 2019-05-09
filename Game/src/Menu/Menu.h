#pragma once
#include <iostream>
#include <vector>
#include "Render.h"
#include "KATMenu.h"
#include "FSprite.h"

class Button
{
    private:
        FSprite* sprite;
        float x, y;
        float sx, sy;
        char* pathnormal;
        char* pathfocus;
        int id;
    public:
        Button(int id, char* pathnormal, char* pathfocus, float x, float y, float sx, float sy);
        ~Button(){delete sprite;}
        int getID(){return id;}

        void focus();
        void unfocus();
        void setPosition(float x, float y);
        void setScale(float sx, float sy);
        void setColor(float r, float g, float b);
        void setRotation(float r);

};


class Menu
{
    protected:
        FSprite* background;
        std::vector<Button*> buttons;
        std::size_t focus;
    public:
        Menu(){focus = 0;}
        ~Menu(){clear();}
        virtual void init() = 0;
        void clear();
        void down();
        void up();
        virtual void update() = 0;
        virtual int click() = 0;
};
