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

    IAComponent(GameObject * owner, Manager * m, GameObject* main): Component(owner, m), main(main){}
    ~IAComponent(){Clear();}

    void Initialice(int mode);
    void run();
    void Clear();

    std::map<std::string,Nodo*> mapa;

    GameObject* main;

    bool didIcollide = false;
    bool onRoute = false;

    std::vector<float> route;

    GameObject* spawnOnFire;
    GameObject* pozoObjetivo;

};