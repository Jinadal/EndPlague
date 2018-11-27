#pragma once
//Headers
#include "Component.h"

class ShootComponent : public Component{
    private:
        float   lastShoot;          //Elapsed time since last shoot
        float   cadencia;           //Shoots per second

        float   damage;             //Damage of projectile
        float   velocity;           //Velocity of projectile
        char    projectileMesh[]    //Mesh of the projectile
        char    projectileTexture[] //Texture of the projectile

    public:

        //Constructor
        ShootComponent(GameObject* g, 
                        float cadencia, 
                        float damage,
                        float velocity,
                        char mesh[],
                        char texture[]):Component(g){

            lastShoot = 0.f;
            this->cadencia = cadencia;
            this->damage = damage;
            this->velocity = velocity;
            this->projectileMesh = mesh;
            this->projectileTexture = texture;
        }
        //Getters&&Setters
        float getCadencia(){return cadencia;}
        float getDamage(){return damage;}
        float getVelocity(){return velocity;}
        char getProjectileMesh(){return projectileMesh;}
        char getProjectileTexture(){return projectileTexture;}

        void setCadencia(float c){cadencia=c;}
        void setVelocity(float v){velocity = f;}
        void setDamage(float d){damage=d;}
        void setProjectileMesh(char m[]){projectileMesh = m;}
        void setProjectileTexture(char t[]){projectileTexture = t;}

        //Methods
        void shoot();
        bool update(float dt);
        float getX();
        float getY();
};
