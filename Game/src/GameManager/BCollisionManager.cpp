#include "BCollisionManager.h"

BCollisionManager* only_instance = NULL;

void BCollisionManager::createComponent(GameObject* owner, float xsize, float ysize, float zsize, float mass)
{
    components.push_back(new BCollisionComponent(owner, this, xsize, ysize, zsize, mass));
    owner->addComponent(components[components.size()-1]);
}



/*
    Update all tendria que actualizar todas las posiciones de 
los objetos en bullet, eso ya lo hace, llamando al  update de 
cada compnente. 

    Una vez hecho esto, tendria que realizar la simulacion y 
resolver las  colisiones, y con las colisiones detectadas 
recorrer todas las situaciones de contacto (Colisiones) y 
hacer en funcion de cada par de colisiones acciones. Segun he
leido se tiene que hacer con un Contact Callback o algo asi

            dynamicsWorld->contactTest(mPlayerObject, resultCallback);
            int numManifolds = dynamicsWorld->getDispatcher()->getNumManifolds();
            if(numManifolds > 0)
            {
            //there's a collision, execute blah blah blah
            }

*/
void BCollisionManager::updateAll(){
    for(std::size_t i = 0; i<components.size(); i++)
    {
        ((BCollisionComponent*)components[i])->update();
    }
}
