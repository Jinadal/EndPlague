#pragma once

#include <vector>
#include <GameObject.h>
#include <RenderManager.h>
#include <MovementManager.h>
#include <ProjectileManager.h>

class ProjectileFabric{

    public:

    //En el constructor incluimos los tipos de proyectil que utilizaremos con la estructura definida abajo

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

    //Metodo para crear una bala de cualquier tipo

    void createBullet(float x, float y, float rz, int k){

        //Creamos el gameobject de la bala con x, y, altura 0 y la rotacion que se nos pasa

        GameObject* a = new GameObject(x, y, 0.f, rz);

        /*Pasamos strings a chars para que sea compatible con los metodos 
          de render (que usan char[], no strings)*/

        std::string me = tipos[k].mesh;
        char *cme = &me[0u];

        std::string tex = tipos[k].texture;
        char *ctex = &tex[0u];

        //Definimos render, que no existia a este nivel
        RenderIrrlicht* render = RenderIrrlicht::getInstance();

        //Creamos el componente render de la bala con la mesh y la textura del tipo que toca
        RenderManager::getInstance()->createComponent(a, render, cme);
        a->getComponent<RenderComponent>()->setTexture(ctex);
        
        //Creamos el componente de movimiento de la bala con la velocidad del tipo que toca
        MovementManager::getInstance()->createComponent(a);
        a->getComponent<MovementComponent>()->setvMax(tipos[k].velocity);

        //Creamos el componente de proyectil para asignarle el danyo del tipo que toca
        ProjectileManager::getInstance()->createComponent(a, tipos[k].damage);

        //Lo agregamos al vector de balas
        projectiles.push_back(a);

    }

    //Metodo para destruir las balas comparando directamente el objeto que se pasa con los del vector

    void kill(GameObject* toKill){
        
        for(int i = 0; i<projectiles.size(); i++){

            if(toKill == projectiles[i]){

                projectiles[i]->toKill();

            }

        }

    }

    private:

        //Vector que almacena los proyectiles creados
        std::vector<GameObject*> projectiles;

        /*Estructura que usaremos para definir todos los tipos de proyectil
          He optado por usar strings porque los char[] necesitan ser la ultima
          variable del struct para poder ser dinamicos (es eso o asignar una 
          longitud fija), y no puede ser porque hay dos en el mismo struct. 
          Arriba se hace la conversion para que funcionen los metodos de render.*/

        struct tipo{
            std::string mesh;
            std::string texture;
            float velocity;
            float damage;
        };

        //Vector de tipos en el que se almacenan todos los tipos creados en el constructor
        std::vector<tipo> tipos;
};