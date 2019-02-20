
#include "IAComponent.h"
#include "IAMovimiento.h"
#include "IASeguimiento.h"
#include "IAPlanificacion.h"
#include "IAGrafos.h"
#include "BPhysicComponent.h"
#include "Nodo.h"
#include "GameObject.h"
#include "Waypoint.h"
#include "IAFire.h"


#include <iostream>

void IAComponent::Initialice(int mode){




// Planificacion 
/*

                 main(sel)

 pared?(sec)      segui(sec)               seguir ruta(sec)                  

 choco? chdir   ¿a rango? segui       ¿Estoy en ruta?  seguir el punto
  


// Planificacion 2.0


                 main(sel)

 pared?(sec)      segui(sec)               seguir ruta(sec)                  

 choco? chdir   ¿a rango? segui3       ¿Estoy en ruta?  seguir el punto






  //Seguimiento personaje

  x y 

  sel raiz
  |       \
  |         \ 
  sel x      sel y 
  |  \        |    \
  |    \      sec y sec yhe
  sec x  sec xwid

  //Seguimiento personaje 2.0

  
                      sel raiz

             sec enX?                            sec enY?
  abs.dx>=abs.dy?   sel goOnX        abs.dx<abs.dy?    sel goOnY

                sec x<-     sec x->                  sec y V     sec y ^

               dx>0? go->  dx<0 go<-              dy>0? go ^     dy<0 go V
  

//Seguimiento personaje 3.0

                                      sel raiz
          
     sec check Area                                 sel follow  
                                      sec enX?                            sec enY?
  En area?     GPS          abs.dx>=abs.dy?   sel goOnX        abs.dx<abs.dy?    sel goOnY

                                          sec x<-     sec x->                  sec y V     sec y ^

                                        dx>0? go->  dx<0 go<-              dy>0? go ^     dy<0 go V



  */

 /////////// MAIN TREE ////////////

if(!mode)
{

    Selector* nodoRaiz = new Selector();
    std::pair<std::string,Nodo*> pRaiz;
    pRaiz.first= "Raiz";
    pRaiz.second = nodoRaiz;

    mapa.insert(pRaiz);


       


        
      
        
        Secuencia* seguirRuta = new Secuencia();
        nodoRaiz->addChild(seguirRuta );

                IA_Graf_CheckRuta* checkruta = new IA_Graf_CheckRuta(gameObject);
                seguirRuta->addChild(checkruta);

                IA_Graf_Checkarea* checkarearute = new IA_Graf_Checkarea(gameObject,main);
                seguirRuta->addChild(checkarearute);

                IA_Graf_FollowRuta* followruta = new IA_Graf_FollowRuta(gameObject, .6f);
                seguirRuta->addChild(followruta);

        Secuencia* decideSeg = new Secuencia();
        nodoRaiz->addChild(decideSeg);

                IA_Plan_InSight* aRango = new IA_Plan_InSight(gameObject, main);
                decideSeg->addChild(aRango);


  ///////////////////////////////////  


//SEGUIMIENTO 3

                Selector* seguimientoDirecto = new Selector();
                decideSeg->addChild(seguimientoDirecto);

                        Secuencia* otraArea = new Secuencia();
                        seguimientoDirecto->addChild(otraArea);

                            IA_Graf_Checkarea* checkarea = new IA_Graf_Checkarea(gameObject,main);
                            otraArea->addChild(checkarea);

                            IA_Graf_LaunchGPS* GPS = new IA_Graf_LaunchGPS(gameObject, main);
                            otraArea->addChild(GPS);

                        // ---------------------------------

                        IA_Seg_ToPlayer* raizIASeg = new IA_Seg_ToPlayer(gameObject, main);

                        seguimientoDirecto->addChild(raizIASeg);

                    

    MoveNone* movenone = new MoveNone(gameObject);
    nodoRaiz->addChild(movenone);
                        
                                        
}

if(mode)
{
    Selector* nodoRaiz2 = new Selector();
    std::pair<std::string,Nodo*> pRaiz2;
    pRaiz2.first= "Raiz";
    pRaiz2.second = nodoRaiz2;

    mapa.insert(pRaiz2);       
      
        
        Secuencia* seguirRuta2 = new Secuencia();
        nodoRaiz2->addChild(seguirRuta2 );

                IA_Graf_CheckRuta* checkruta2 = new IA_Graf_CheckRuta(gameObject);
                seguirRuta2->addChild(checkruta2);

                Selector* pozoOCasa = new Selector();
                seguirRuta2->addChild(pozoOCasa);

                    Secuencia* aPozo = new Secuencia();
                    pozoOCasa->addChild(aPozo);

                        IA_Fire_haveWater* haveWaterP = new IA_Fire_haveWater(gameObject);
                        aPozo->addChild(haveWaterP);

                        IA_Graf_FollowRuta* followruta2 = new IA_Graf_FollowRuta(gameObject, 1.2F);
                        aPozo->addChild(followruta2);

                    IA_Graf_FollowRuta* followruta3 = new IA_Graf_FollowRuta(gameObject, 3.1F);
                    pozoOCasa->addChild(followruta3);

        Secuencia* seeFire = new Secuencia();
        nodoRaiz2->addChild(seeFire);

                IA_Fire_seefire* onFire = new IA_Fire_seefire(gameObject);
                seeFire->addChild(onFire);

                Selector* wellOrSpawn = new Selector();
                seeFire->addChild(wellOrSpawn);

                    Secuencia* toWell = new Secuencia();
                    wellOrSpawn->addChild(toWell);
                    
                        IA_Fire_haveWater* haveWater = new IA_Fire_haveWater(gameObject);
                        toWell->addChild(haveWater);

                        IA_Fire_searchWell* buscarPozo = new IA_Fire_searchWell(gameObject);
                        toWell->addChild(buscarPozo);

                        IA_Fire_GPStoWell* AlPozo = new IA_Fire_GPStoWell(gameObject);
                        toWell->addChild(AlPozo);

                    IA_Fire_GPStoSpawn* AlSpawn = new IA_Fire_GPStoSpawn(gameObject);
                    wellOrSpawn->addChild(AlSpawn);

        
        MoveNone* movenone2 = new MoveNone(gameObject);
        nodoRaiz2->addChild(movenone2);
                        
}

            
}

void IAComponent::run(){


if(!mapa.find("Raiz")->second->run()){
    gameObject->getComponent<BPhysicComponent>()->setvMax(0.f);
}



  /*mapa.find("Movimiento")->second->run();

  mapa.find("Seguimiento")->second->run();

     */ 
}

void IAComponent::Clear()
{
      

    for(std::map<std::string, Nodo*>::iterator it = mapa.begin(); it != mapa.end(); it++)
    {
       delete it->second;

    }//borrar el mapa 
    
    
    
    mapa.clear();
}

