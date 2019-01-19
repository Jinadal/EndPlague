#pragma once
#include <vector>

class Waypoint
{

    public:
        Waypoint(int x, int y, bool ocupado){_x = x; _y = y; _ocupado = ocupado;}

        virtual ~Waypoint(){}

        float _x, _y;
        bool _ocupado;

};

class Conexion
{
    public:
        Conexion(Waypoint* origin, Waypoint* end, float cost){ origen = origin; destino = end; coste = cost;}
        virtual ~Conexion(){}
        Waypoint* origen;
        Waypoint* destino;

        float coste;

};

struct Pointrecord {
    Waypoint* waypoint;
    Conexion* connection;
    float costeactual;

};

class Grafo
{
    public:
        Grafo(){}
        virtual ~Grafo(){}

        std::vector<Conexion*> _conexiones;

        void Initialice();

        Waypoint* getNearestWaypoint(float X, float Y);
        std::vector<Conexion*> getConections(Waypoint* currentWaypoint);

        std::vector<Conexion*> pathfindingDijkstra(Waypoint* currentWaypoint, Waypoint* objetiveWaypoint);
        Pointrecord* getSmallest(std::vector<Pointrecord*> list);
        Pointrecord* buscar(std::vector<Pointrecord*> list, Waypoint* nodo);
        bool estaEnLaLista(std::vector<Pointrecord*> list, Waypoint* nodo);

      


};

