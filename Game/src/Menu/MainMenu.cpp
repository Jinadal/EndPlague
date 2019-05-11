#include "MainMenu.h"

MainMenu::MainMenu() : Menu()
{
    //Background
    setBackground((char*)"res/sprites/menus/Fondo.png");

    //Buttons
    Button* button = new Button(1, (char*)"res/sprites/menus/Inicio.png", 
                                        (char*)"res/sprites/menus/Inicio_H.png",200, 200);
    buttons.push_back(button);
    
    button = new Button(2, (char*)"res/sprites/menus/Opciones.png", 
                                        (char*)"res/sprites/menus/Opciones_H.png",200, 450);
    buttons.push_back(button);
    
    button = new Button(3, (char*)"res/sprites/menus/Salir.png", 
                                        (char*)"res/sprites/menus/Salir_H.png",200, 700);
    buttons.push_back(button);

    buttons[focus]->focus();
}
