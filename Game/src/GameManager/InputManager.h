#pragma once
#include "Manager.h"

class GameObject;
class InputManager : public Manager{
    private:
        InputManager():Manager(){}
        static InputManager *only_instance;
        float cursorX, cursorY;
    public:
        ~InputManager(){only_instance=nullptr;}
        static InputManager *getInstance(){
            if(!only_instance){only_instance = new InputManager();}
            return only_instance;
        }

        void createComponent(GameObject* owner);
        void setCursorPosition(float x, float y);
        void updateAll(float dt);
};