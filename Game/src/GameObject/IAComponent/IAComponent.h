#pragma once
#include "Nodo.h"
#include "Component.h"
#include "GameObject.h"
#include <map>
#include "Waypoint.h"

using namespace std;

class IAComponent : public Component
{

    public:

    IAComponent(GameObject * owner, Manager * m, GameObject* main): Component(owner, m), main(main){}
    ~IAComponent(){}

    void Initialice();
    void run();

    std::map<std::string,Nodo*> mapa;

    GameObject* main;

    bool didIcollide = false;
    bool hasWaypoint = false;

    Waypoint * waypoint;

    Grafo* grafo;

};