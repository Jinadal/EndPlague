#pragma once

#include <vector>
#include <GameObject.h>
#include <RenderManager.h>
#include <ProjectileManager.h>

class ProjectileFabric{

    public:

    ProjectileFabric(){

        //Type 0
        struct tipo hacha;
        hacha.mesh = "res/Bullety.obj";
        hacha.texture = "res/green.bmp";
        hacha.velocity = 40.f;
        hacha.damage = 24.f;

        tipos.push_back(hacha);

        //Type 1
        struct tipo flecha;
        flecha.mesh = "res/Bullety.obj";
        flecha.texture = "res/red.bmp";
        flecha.velocity = 40.f;
        flecha.damage = 24.f;

        tipos.push_back(flecha);
    }

    void createBullet(float x, float y, float rz, int k){

        GameObject* a = new GameObject(x, y, 0.f, rz);

        RenderManager::getInstance()->createComponent(a, render, tipos[k].mesh);
        a->getComponent<RenderComponent>()->setTexture(tipos[k].texture);

        MovementManager::getInstance()->createComponent(a);
        a->getComponent<MovementComponent>()->setvMax(tipos[k].velocity);

        ProjectileManager::getInstance()->createComponent(a, tipos[k].damage);

        projectiles.push_back(a);

    }

    void kill(GameObject* toKill){
        
        for(int i = 0; i<projectiles.size(); i++){

            if(toKill == projectiles[i]){

                projectiles[i]->kill();

            }

        }

    }

    private:

        std::vector<GameObject*> projectiles;

        struct tipo{
            std::string mesh;
            std::string texture;
            float velocity;
            float damage;
        };

        std::vector<tipo> tipos;
};