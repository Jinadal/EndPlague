#pragma once
#include <map>
#include "Component.h"

class GameObject;
class Waypoint;
class Nodo;
class Grafo;
class IAComponent : public Component
{

    public:

    IAComponent(GameObject * owner, Manager * m, GameObject* main, int lv): Component(owner, m), main(main)
    {
        nivel = lv;
        setPatrollingRoute(owner, nivel);
    }
    ~IAComponent(){Clear();}

    void Initialice(int mode);
    void run();
    void Clear();
    void setPatrollingRoute(GameObject* owner, int nivel);

    int nivel;
    std::map<std::string,Nodo*> mapa;

    GameObject* main;

    bool didIcollide = false;
    bool onRoute = false;
    bool onPatrol = false;


    std::vector<float> route;
    std::vector<float> patrollingRoute;
    std::vector<float> currentpatrollingRoute;



    GameObject* spawnOnFire;
    GameObject* pozoObjetivo;

};