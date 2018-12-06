#pragma once
//Headers
#include "Component.h"
#include "GameObject.h"


class ShootComponent : public Component{
    private:
        float   lastShoot;          //Elapsed time since last shoot
        float   cadencia;           //Shoots per second
        int     projectileKind;          //Kind of bullet o create
        bool    wantsShoot;
    
    public:

        //Constructor
        ShootComponent(GameObject* g, Manager* m, float cadencia, int kind):Component(g, m){
            wantsShoot = false;
            lastShoot = 0.f;
            this->cadencia = cadencia;
            this->projectileKind = kind;
        }
        ~ShootComponent(){}
        //Getters&&Setters
        float getCadencia(){return cadencia;}
        int getProjectileKind(){return projectileKind;}

        void setCadencia(float c){cadencia=c;}
        void setProjectileKind(int pk){projectileKind = pk;}

        //Methods
        void shoot();
        bool update(float dt);
        float getX();
        float getY();
        float getRZ();
};
