#include "Game.h"
#include "SoundSystem.h"

int main(){
    

    CAudioEngine* c = new CAudioEngine();

    c->Init();
    c->LoadSound("res/Seleccion.wav", false, true, false);
    c->PlaySounds("res/Seleccion.wav", Vector3{0, 0, 0}, 30);
    while(true){
        c->Update();
    }
    


    
    //Game::getInstance()->run();

    return 0;
}