#include "Menu.h"
#include "FSprite.h"
#include <iostream>

void Menu::down()
{
    buttons[focus]->unfocus();
    if(focus >= buttons.size() - 1)
    {
        focus = 0;
    }
    else
    {
        focus++;
    }
    buttons[focus]->focus();
};
void Menu::up()
{
    buttons[focus]->unfocus();
    if(focus <= 0)
    {
        focus = buttons.size()-1;
    }
    else
    {
        focus--;
    }
    buttons[focus]->focus();
}


void Menu::clear()
{
    delete background; 
    for(size_t i = 0; i<buttons.size(); i++) 
        delete buttons[i]; 
    
    buttons.clear();
}

Button::Button(int id, char* pathnormal, char* pathfocus, float x, float y, float sx, float sy)
{
    this->id = id;
    this->x = x;
    this->sx = sx;
    this->y = y;
    this->sy = sy;
    this->pathnormal = pathnormal;
    this->pathfocus = pathfocus;
    sprite = Render::getInstance()->getSprite(pathnormal, x, y, sx, sy, 0.f, 1.f, 1.f, 1.f);
}

void Button::focus()
{
    delete sprite;
    sprite = Render::getInstance()->getSprite(pathfocus, x, y, sx, sy, 0.f, 1.f, 1.f, 1.f);
}

void Button::unfocus()
{
    delete sprite;
    sprite = Render::getInstance()->getSprite(pathnormal, x, y, sx, sy, 0.f, 1.f, 1.f, 1.f);
}

void Button::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
    sprite->setPosition(x, y);
}

void Button::setScale(float sx, float sy)
{
    this->sx = sx;
    this->sy = sy;
    sprite->setScale(sx, sy);
}

void Button::setColor(float r, float g, float b)
{
    sprite->setColor(r, g, b);
}
void Button::setRotation(float r)
{
    sprite->setRotation(r);
}
