
#include "IAComponent.h"
#include "IAMovimiento.h"
#include "IASeguimiento.h"
#include "IAPlanificacion.h"
#include "IAGrafos.h"
#include "BPhysicComponent.h"
#include <iostream>


void IAComponent::Initialice(){




// Planificacion
/*

                 main(sel)

 pared?(sec)      segui(sec)      movi

 choco? chdir   ¿a rango? segui        
  




    //Movimiento

  
  raiz(sel)
  |       \
  |         \
  sec        moveRight
  |   \
  |     \
  pared?  moveUP


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
  






  */

 /////////// MAIN TREE ////////////



    Selector* nodoRaiz = new Selector();
    pair<string,Nodo*> pRaiz;
    pRaiz.first= "Raiz";
    pRaiz.second = nodoRaiz;

    mapa.insert(pRaiz);


    Secuencia* hayColl = new Secuencia();
    nodoRaiz->addChild(hayColl);

    IA_Plan_DidICollide* plan_didIcollide = new IA_Plan_DidICollide(gameObject);
    hayColl->addChild(plan_didIcollide);

    IA_Plan_ChangeDirection* plan_changeDirection = new IA_Plan_ChangeDirection(gameObject);
    hayColl->addChild(plan_changeDirection);


    Secuencia* decideSeg = new Secuencia();
    nodoRaiz->addChild(decideSeg);

    IA_Plan_InSight* aRango = new IA_Plan_InSight(gameObject, main);
    decideSeg->addChild(aRango);

    Secuencia* hasAWaypoint = new Secuencia();
    nodoRaiz->addChild(hasAWaypoint);

    IA_Plan_HaveWaypoint* checkWay = new IA_Plan_HaveWaypoint(gameObject);
    hasAWaypoint->addChild(checkWay);

    IA_Graf_SetAWaypoint* setWay = new IA_Graf_SetAWaypoint(gameObject);
    hasAWaypoint->addChild(setWay);


  ///////////////////////////////////  





    Selector* raizIAmov = new Selector();
    pair<string,Nodo*> p;
    p.first= "Movimiento";
    p.second = raizIAmov;

    mapa.insert(p);

   

    Secuencia * pared_arriba = new Secuencia();
    raizIAmov->addChild(pared_arriba);

    //MoverIzda* movelft1 = new MoverIzda(gameObject);
    //pared_arriba->addChild(movelft1);


    Pared* pared = new Pared(gameObject);
    pared_arriba->addChild(pared);


   // MoverDcha* movedcha = new MoverDcha(gameObject);
   // pared_arriba->addChild(movedcha);

    MoverArriba* moveup = new MoverArriba(gameObject, main);
    pared_arriba->addChild(moveup);



    MoverIzda* movelft = new MoverIzda(gameObject, main);
    raizIAmov->addChild(movelft);

    



    // ---------------------------------

    Selector* raizIASeg = new Selector();

    pair<string,Nodo*> ps;
    ps.first= "Seguimiento";
    ps.second = raizIASeg;

    mapa.insert(ps);

  ///
    decideSeg->addChild(raizIASeg);
  ///


      Secuencia* seg_enX = new Secuencia();
      raizIASeg->addChild(seg_enX);

            IA_Seg_DifX* seg_difenX = new IA_Seg_DifX(gameObject, main);
            seg_enX->addChild(seg_difenX);

            Selector* seg_goOnX = new Selector();
            seg_enX->addChild(seg_goOnX);


                Secuencia* seg_XIzq = new Secuencia();
                seg_goOnX->addChild(seg_XIzq);

                         IA_Seg_CheckXIzd* seg_checkXIzd = new IA_Seg_CheckXIzd(gameObject, main);
                         seg_XIzq->addChild(seg_checkXIzd);

                         MoverDcha* seg_movDcha = new MoverDcha(gameObject, main);
                         seg_XIzq->addChild(seg_movDcha);


                Secuencia* seg_XDer = new Secuencia();
                seg_goOnX->addChild(seg_XDer);

                         IA_Seg_CheckXDer* seg_checkXDer = new IA_Seg_CheckXDer(gameObject, main);
                         seg_XDer->addChild(seg_checkXDer);

                         MoverIzda* seg_movIzda = new MoverIzda(gameObject, main);
                         seg_XDer->addChild(seg_movIzda);


                



      Secuencia* seg_enY = new Secuencia();
      raizIASeg->addChild(seg_enY);

          IA_Seg_DifY* seg_difenY = new IA_Seg_DifY(gameObject, main);
          seg_enY->addChild(seg_difenY);

          Selector* seg_goOnY = new Selector();
          seg_enY->addChild(seg_goOnY);

                Secuencia* seg_YAbj = new Secuencia();
                seg_goOnY->addChild(seg_YAbj);

                      IA_Seg_CheckYAbj* seg_checkYAbj = new IA_Seg_CheckYAbj(gameObject, main);
                      seg_YAbj->addChild(seg_checkYAbj);

                      MoverArriba* seg_movArri = new MoverArriba(gameObject, main);
                      seg_YAbj->addChild(seg_movArri);


                Secuencia* seg_YArr = new Secuencia();
                seg_goOnY->addChild(seg_YArr);

                      IA_Seg_CheckYArr* seg_checkYArr = new IA_Seg_CheckYArr(gameObject, main);
                      seg_YArr->addChild(seg_checkYArr);

                      MoverAbajo* seg_movAbjo = new MoverAbajo(gameObject, main);
                      seg_YArr->addChild(seg_movAbjo);
                      


                

/*

    Selector* xgeneral = new Selector();
    raizIASeg->addChild(xgeneral);

      Selector* ygeneral = new Selector();
    raizIASeg->addChild(ygeneral);


    Secuencia* enx = new Secuencia();
    xgeneral->addChild(enx);
    
    Secuencia* enxwid = new Secuencia();
    xgeneral->addChild(enxwid);

    Secuencia* eny = new Secuencia();
    ygeneral->addChild(eny);

        Secuencia* enyhei = new Secuencia();
    ygeneral->addChild(enyhei);



    CheckX* checkx = new CheckX(gameObject, main);
    enx->addChild(checkx);

    MoverDcha* xmd = new MoverDcha(gameObject);
    enx->addChild(xmd);

    CheckXwid* checkxwid = new CheckXwid(gameObject,main);
    enxwid->addChild(checkxwid);

    MoverIzda* xmi = new MoverIzda(gameObject);
    enxwid-> addChild(xmi);

    CheckY* checky = new CheckY(gameObject,main);
    eny->addChild(checky);

    MoverAbajo* ymab = new MoverAbajo(gameObject);
    eny->addChild(ymab);

      CheckYhei* checkyhei = new CheckYhei(gameObject,main);
    enyhei->addChild(checkyhei);

    MoverArriba* ymar = new MoverArriba(gameObject);
    enyhei->addChild(ymar);

    */
}

void IAComponent::run(){


if(!mapa.find("Raiz")->second->run()){
    gameObject->getComponent<BPhysicComponent>()->setvMax(0.f);
}



  /*mapa.find("Movimiento")->second->run();

  mapa.find("Seguimiento")->second->run();

     */ 
}

