
#include "IAComponent.h"
#include "IAMovimiento.h"
#include "IASeguimiento.h"
#include <iostream>


void IAComponent::Initialice(){


    //Movimiento

  /*
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

  


  
  */
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

    MoverArriba* moveup = new MoverArriba(gameObject);
    pared_arriba->addChild(moveup);



    MoverIzda* movelft = new MoverIzda(gameObject);
    raizIAmov->addChild(movelft);

    



    // ---------------------------------

    Selector* raizIASeg = new Selector();

    pair<string,Nodo*> ps;
    ps.first= "Seguimiento";
    ps.second = raizIASeg;

    mapa.insert(ps);

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
}

void IAComponent::run(){


  mapa.find("Movimiento")->second->run();

  mapa.find("Seguimiento")->second->run();

      
}

