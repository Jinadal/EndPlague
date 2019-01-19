#include "Waypoint.h"
#include <cmath>


void Grafo::Initialice()
{

    Waypoint* w1 = new Waypoint(10,10,false);

    Waypoint* w2 = new Waypoint(10,15,false);

    Conexion* c1 = new Conexion(w1,w2, 1.f);

    _conexiones.push_back(c1);
    
}

Waypoint* Grafo::getNearestWaypoint(float x, float y)
{
    Waypoint* result = _conexiones[0]->origen;

    float currentdx = result->_x - x;
    float currentdy = result->_y - y;

    std::vector<Conexion*>::iterator iter;
    for(iter = _conexiones.begin(); iter!=_conexiones.end(); iter ++)
    {
        float newdx = (*iter)->origen->_x - x;
        float newdy = (*iter)->origen->_y - y;

        if(fabs(newdx)< fabs(currentdx) && fabs(newdy)< fabs(currentdy))
        {
            result = (*iter)->origen;
            currentdx = newdx;
            currentdy = newdy;
            
        }




        newdx = (*iter)->destino->_x - x;
        newdy = (*iter)->destino->_y - y;

        if(fabs(newdx)< fabs(currentdx) && fabs(newdy)< fabs(currentdy))
        {
            result = (*iter)->destino;
            currentdx = newdx;
            currentdy = newdy;
            
        }
    }

    return result;

}

std::vector<Conexion*> Grafo::getConections(Waypoint* currentWaypoint)
{

    std::vector<Conexion*> result;

     std::vector<Conexion*>::iterator iter;
    for(iter = _conexiones.begin(); iter!=_conexiones.end(); iter ++)
    {

        if((*iter)->origen == currentWaypoint) result.push_back((*iter));
    }

    return result;
}

 

std::vector<Conexion*> Grafo::pathfindingDijkstra(Waypoint* startWaypoint, Waypoint* objetiveWaypoint)
{

    std::vector<Conexion*> path;

    Pointrecord* startRecord;
    Pointrecord* endRecord;
    Pointrecord* current;

    startRecord->waypoint = startWaypoint;
    //startRecord->connection = NULL;
    startRecord->costeactual = 0.f;

    std::vector<Pointrecord*> open;
    open.push_back(startRecord);
    std::vector<Pointrecord*> closed;


    while(!open.empty())
    {
        current = getSmallest(open);

        if(current->waypoint == objetiveWaypoint) break;

        std::vector<Conexion*> connections = getConections(current->waypoint);

        std::vector<Conexion*>::iterator iter;

        for(iter = connections.begin(); iter!=connections.end(); iter ++)
        {
            Waypoint* endNode = (*iter)->destino;
            float endNodeCost = current->costeactual + (*iter)->coste;

            if(estaEnLaLista(closed, endNode))
            { 
                continue;
            }
            else{

                if(estaEnLaLista(open, endNode))
                {
                    Pointrecord* endRecord = buscar(open, endNode);
                    if(endRecord->costeactual <= endNodeCost)
                    {
                        continue;
                    }
                      
                }
                else{
                    //Pointrecord* endRecord;
                    endRecord->waypoint = endNode;
                }    

                endRecord->costeactual = endNodeCost;
                endRecord->connection = (*iter);
                if(!estaEnLaLista(open, endNode))
                    open.push_back(endRecord);
            }


        }
        for( std::vector<Pointrecord*>::iterator iter2 = open.begin(); iter2 != open.end(); ++iter2 )
        {
            if( *iter2 == current)
            {
                open.erase( iter2 ); //posible pete aqui en el futuro, creo que no, pero si eso es porque llega a la ultima posicion y la borra y luego sigue el bucle.
                break;
            }
        }
        closed.push_back(current);
        


    }

    if(current->waypoint != objetiveWaypoint) return path;


    while(current->waypoint != startWaypoint){
        std::vector<Conexion*>::iterator iter = path.begin();
        path.insert(iter,current->connection);
        current = buscar(closed,current->connection->origen);
    }

    return path;
}

Pointrecord* Grafo::getSmallest(std::vector<Pointrecord*> list)
{
     std::vector<Pointrecord*>::iterator iter = list.begin();

    Pointrecord* result = *iter;

    for(iter = list.begin()+1; iter!=list.end(); iter ++)
    {
        if(result->costeactual > (*iter)->costeactual) result = (*iter);
    }

    return result;
}

Pointrecord* Grafo::buscar(std::vector<Pointrecord*> list, Waypoint* nodo)
{
     std::vector<Pointrecord*>::iterator iter;

    Pointrecord* result;

    for(iter = list.begin(); iter!=list.end(); iter ++)
    {
        if(nodo == (*iter)->waypoint){
            result = (*iter);
            break;
        }
    }

    return result;
}

bool Grafo::estaEnLaLista(std::vector<Pointrecord*> list, Waypoint* nodo)
{
     std::vector<Pointrecord*>::iterator iter;

    for(iter = list.begin(); iter!=list.end(); iter ++)
    {
        if((*iter)->waypoint == nodo) return true;
    }

    return false;
}