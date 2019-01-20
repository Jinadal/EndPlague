#include "Waypoint.h"
#include <cmath>


void Grafo::Initialice()
{

    Waypoint* w1 = new Waypoint(10,10);

    Waypoint* w2 = new Waypoint(10,15);

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

    std::vector<Conexion*> path; //Final path

    Pointrecord* startRecord;   //Starting waypoint
    Pointrecord* endRecord;     //Conection finishing waypoint
    Pointrecord* current;       //Actual waypoint

    startRecord->waypoint = startWaypoint;  
    //startRecord->connection = NULL;
    startRecord->costeactual = 0.f;     //Var for weight comparation

    std::vector<Pointrecord*> open;     //open waypoint without testing
    open.push_back(startRecord);
    std::vector<Pointrecord*> closed;   //closed waypoint already tested


    while(!open.empty())
    {
        current = getSmallest(open);    //from open list we get the least weight pointrecord

        if(current->waypoint == objetiveWaypoint) break;    //if current=destiny, break

        std::vector<Conexion*> connections = getConections(current->waypoint);  //get all connections from actual waypoint

        std::vector<Conexion*>::iterator iter;

        for(iter = connections.begin(); iter!=connections.end(); iter ++)   
        {
            Waypoint* endNode = (*iter)->destino;                           //get connections end
            float endNodeCost = current->costeactual + (*iter)->coste;      //add connection weight

            if(estaEnLaLista(closed, endNode))  //compare if endnode is in closed list
            { 
                continue;
            }
            else{

                if(estaEnLaLista(open, endNode))    //looking if next waypoint has connections yet to visit
                {
                    Pointrecord* endRecord = buscar(open, endNode); //next pointrecord
                    if(endRecord->costeactual <= endNodeCost)       //not best way  
                    {
                        continue;
                    }
                      
                }
                else{           
                    //Pointrecord* endRecord;
                    endRecord->waypoint = endNode;
                }    

                endRecord->costeactual = endNodeCost;   //we save the last connection with less cost
                endRecord->connection = (*iter);        //most optimal connection at the moment from current point
                if(!estaEnLaLista(open, endNode))       //we add to open list the new node
                    open.push_back(endRecord);
            }


        }
        for( std::vector<Pointrecord*>::iterator iter2 = open.begin(); iter2 != open.end(); ++iter2 )
        {
            if( *iter2 == current)  //add current pointrecord to close list
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