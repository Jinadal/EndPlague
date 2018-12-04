
#include "IAComponent.h"
#include "IAMovimiento.h"
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

    
    
}

void IAComponent::run(){


  mapa.find("Movimiento")->second->run();

      
}

