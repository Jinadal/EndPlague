#pragma once
//Headers
#include "Component.h"

class ShootComponent : public Component{
    private:
        float lastShoot;        //Elapsed time since last shoot
        float cadencia;         //Shoots per second 
        float damage;           //Damage of bullet
        char projectileMesh[]   //Mesh of the projectile
        char projectileTexture[]//Texture of the projectile

    public:

        //Constructor
        ShootComponent(GameObject* g, float cadencia, float damage):Component(g){
            lastShoot = 0.f;
            this->cadencia = cadencia;
            this->damage = damage;
        }
        //Getters&&Setters
        float getCadencia(){return cadencia;}
        float getDamage(){return damage;}

        void setCadencia(float c){cadencia=c;}
        void setProjectileMesh(char m[]){projectileMesh = m;}
        void setProjectileTexture(char t[]){projectileTexture = t;}

        //Methods
        void shoot();
        void update(float dt);
    
};
