#include "Waypoint.h"
#include <cmath>
#include "Area.h"

void GPS::Initialice()
{

    addWaypoint(0,0);
   // addWaypoint(5,0);
    addWaypoint(0,-10);
    addWaypoint(-7,5);
   



    addArea(-15,5, 0, -5);
    addArea(0,5, 15, -5);
    addArea(-15,-5, 0, -15);
    addArea(0,-5, 15, -15);
    



    addWaypointToArea(0,0);
    addWaypointToArea(0,2);

    addWaypointToArea(1,0);
  //  addWaypointToArea(1,1);

    addWaypointToArea(2,2);
    addWaypointToArea(2,1);

  //  addWaypointToArea(3,1);
    addWaypointToArea(3,1);
 




    //addConexionToGraph(0,1);
   // addConexionToGraph(1,0);

    addConexionToGraph(1,2);
    //addConexionToGraph(2,1);

    addConexionToGraph(0,2);
   //addConexionToGraph(3,0);

    //addConexionToGraph(2,3);
    //addConexionToGraph(3,2);

    

/*
    addWaypoint(5,10);
    addWaypoint(10,15);
    addWaypoint(15,10);
    addWaypoint(20,15);


    addArea(0,0, 10, 10);
    addArea(10,0, 20, 10);
    addArea(0,10, 10, 20);
    addArea(10,10, 20, 20);
    addArea(20,10, 30, 20);
    
    addWaypointToArea(0,0);
   
    addWaypointToArea(1,2);
    

    addWaypointToArea(2,0);
    addWaypointToArea(2,1);

 
    addWaypointToArea(3,1);
    addWaypointToArea(3,2);
    addWaypointToArea(3,3);

    addWaypointToArea(4,3);




    addConexionToGraph(0,1, 1);
    addConexionToGraph(1,0, 1);

    addConexionToGraph(1,2, 1);
    addConexionToGraph(2,1, 1);

    addConexionToGraph(1,3, 1);
    addConexionToGraph(3,1, 1);



    addConexionToGraph(2,3, 1);
    addConexionToGraph(3,2, 1);

 

*/
    
}

Waypoint* Grafo::getNearestWaypoint(float x, float y)
{
    Waypoint* result = _conexiones.front()->origen;

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

 

pesoPath* Grafo::pathfindingDijkstra(Waypoint* startWaypoint, Waypoint* objetiveWaypoint) //peta aká
{

    std::vector<Conexion*> path; //Final path
    pesoPath* pesopath = new pesoPath();
    std::vector<Pointrecord*> open;     //open waypoint without testing



    Pointrecord* startRecord;   //Starting waypoint
    Pointrecord* endRecord = new Pointrecord();     //Conection finishing waypoint
    Pointrecord* current;       //Actual waypoint

    startRecord->waypoint = startWaypoint;  
    //startRecord->connection = NULL;
    startRecord->costeactual = 0.f;     //Var for weight comparation


    

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
            Waypoint* endNode = (*iter)->destino;         
           // endRecord = current;                  //get connections end
            float endNodeCost = current->costeactual + (*iter)->coste;      //add connection weight

            if(estaEnLaLista(closed, endNode))  //compare if endnode is in closed list
            { 
                continue;
            }
            else{

                if(estaEnLaLista(open, endNode))    //looking if next waypoint has connections yet to visit
                {
                     endRecord = buscar(open, endNode); //next pointrecord
                    if(endRecord->costeactual <= endNodeCost)       //not best way  
                    {
                        continue;
                    }
                      
                }
                else{       
                    Pointrecord* newRecord = new Pointrecord();

                   newRecord->waypoint = endNode;
                   newRecord->costeactual = endNodeCost;
                   newRecord->connection = (*iter); 
                   open.push_back(newRecord); 
                   continue;
                }    

              endRecord->costeactual = endNodeCost;   //we save the last connection with less cost
               endRecord->connection = (*iter);        //most optimal connection at the moment from current point
                if(!estaEnLaLista(open, endNode))       //we add to open list the new node
                   open.push_back(endRecord);
            }


        }
        for( std::vector<Pointrecord*>::iterator iter2 = open.begin(); iter2 != open.end(); iter2++ )
        {
            if( *iter2 == current)  //add current pointrecord to close list
            {
                open.erase( iter2 ); //posible pete aqui en el futuro, creo que no, pero si eso es porque llega a la ultima posicion y la borra y luego sigue el bucle.
                break;
            }
        }
        closed.push_back(current);
        


    }

    if(current->waypoint != objetiveWaypoint) return pesopath;

    pesopath->peso = current->costeactual;
    while(current->waypoint != startWaypoint){
        std::vector<Conexion*>::iterator iter = path.begin();
        path.insert(iter,current->connection);
        current = buscar(closed,current->connection->origen);
    }
    pesopath->path = path;
    return pesopath;
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


void Grafo::addConexion(Waypoint* w1, Waypoint* w2)
{
    float peso = round(sqrt(pow(w2->_x - w1->_x,2) + pow(w2->_y - w2->_y,2)));
    _conexiones.push_back(new Conexion(w1,w2,peso));
    _conexiones.push_back(new Conexion(w2,w1,peso));

}


void GPS::addArea(float xsup, float ysup, float xinf, float yinf)
{
     AML.push_back(new Area(xsup,ysup,xinf,yinf));

}


void GPS::addWaypoint(float coorX, float coorY)
{
    ways.push_back(new Waypoint(coorX,coorY));
}


void GPS::addWaypointToArea(int a, int w)
{
    AML[a]->addWaypoint(ways[w]);
}


void GPS::addConexionToGraph(int w1, int w2)
{
    graph->addConexion(ways[w1], ways[w2]);
}

std::vector<float> GPS::getWay(float xi, float yi, float xf, float yf )
{
    int ai=0; 
    int af=0;
    std::vector<float> returno;

    for (std::size_t i = 0; i< AML.size(); i++)
    {
        if(AML[i]->checkinArea(xi,yi))
        {
            ai = i;
        }

        if(AML[i]->checkinArea(xf,yf))
        {

            af = i;
        }

    }

    if(af == ai)
    {
        
        returno = {xf,yf};
        return returno;
    }

    std::vector<Waypoint*> wai = AML[ai]->getWaypoints();
    std::vector<Waypoint*> waf = AML[af]->getWaypoints();

    float minweight=10000000000.f;
    float auxweight = 0.f;
    std::vector<Conexion*> minway;
    std::vector<Conexion*> auxway;

    for(std::size_t i = 0; i<wai.size(); i++)
    {
        for(std::size_t f = 0; f<waf.size(); f++)
        {

            pesoPath* current = graph->pathfindingDijkstra(wai[i], waf[f]);

            auxweight = current->peso;
            if(auxweight<minweight)
            {
                minway = current->path;
                minweight = auxweight;
            }
        }
    }

   
    for(std::size_t i = 0; i<minway.size(); i++)
   {
       if(i==0)
       {
            returno.push_back(minway[i]->origen->_x);
            returno.push_back(minway[i]->origen->_y);
       }
       returno.push_back(minway[i]->destino->_x);
       returno.push_back(minway[i]->destino->_y);

   }
    returno.push_back(xf);
    returno.push_back(yf);

    return returno;
}

