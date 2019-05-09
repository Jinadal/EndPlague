#include "MainMenu.h"
#include "Render.h"
#include "FSprite.h"

void MainMenu::init()
{
    //Scale
    int screenWidth, screenHeight;
    Render::getInstance()->getRender()->getWindowSize(screenWidth, screenHeight);
    float sh = (float)(screenHeight / 1086.f);
    float sw = (float)(screenWidth / 1930.f);
    

    //Background
    background = Render::getInstance()->getRender()->getSprite((char*)"res/sprites/menus/Fondo.png", 0, 0, 100, 100, 0.f, 1.f, 1.f, 1.f);
    
    float width = background->getWidth() * sw * 1.f;
    float height = background->getHeight() * sh * 1.f;

    background->setScale(width, height);

    //Buttons
    Button* button = new Button(1, (char*)"res/sprites/menus/Inicio.png", 
                                        (char*)"res/sprites/menus/Inicio_H.png",100, 100, 100, 100);
    buttons.push_back(button);
    
    button = new Button(2, (char*)"res/sprites/menus/Opciones.png", 
                                        (char*)"res/sprites/menus/Opciones_H.png",100, 300, 100, 100);
    buttons.push_back(button);
    
    button = new Button(3, (char*)"res/sprites/menus/Salir.png", 
                                        (char*)"res/sprites/menus/Salir_H.png",100, 400, 100, 100);
    buttons.push_back(button);

    buttons[focus]->focus();
}

int MainMenu::click()
{
    return buttons[focus]->getID();
}


void MainMenu::update()
{
    //Scale
    int screenWidth, screenHeight;
    Render::getInstance()->getRender()->getWindowSize(screenWidth, screenHeight);
    float sh = (float)(screenHeight / 1086.f);
    float sw = (float)(screenWidth / 1930.f);


    //Background    
    float width = background->getWidth() * sw * 1.f;
    float height = background->getHeight() * sh * 1.f;
    background->setScale(width, height);

}