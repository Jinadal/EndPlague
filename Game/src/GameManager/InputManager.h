#pragma once
#include "Manager.h"

class GameObject;
class InputManager : public Manager{
    private:
        InputManager():Manager(){}
        static InputManager *only_instance;
        float cursorX, cursorY;
    public:
        virtual ~InputManager(){
            only_instance=NULL;}
        //Constructor Singletone
        static InputManager *getInstance(){
            if(only_instance == NULL){only_instance = new InputManager();}
            return only_instance;
        }

        void createComponent(GameObject* owner);
        void setCursorPosition(float x, float y);
        void updateAll(float dt);
};