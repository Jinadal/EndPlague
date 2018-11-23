#include "CollisionComponent.h"

#include <cmath>

#include <iostream>

bool CollisionComponent::testCollision(CollisionComponent *com)
{

    //Recojo los GameObjects, de este componente y del que me pasan
    GameObject *obj1 = this->getGameObject();
    GameObject *obj2 = com->getGameObject();


    //Diferencia entre las posiciones x e y de los dos objetos, el que me pasan menos este
    float dx = obj2->getX() - obj1->getX();
    float dy = obj2->getY() - obj1->getY();

    //si abs(dif en X) es menor que la suma del punto medio de las anchuras, es decir, que la distancia entre las x sea menor que la suma de los puntos medios
    // y lo mismo pero para la diferencia en Y y las alturas
    if(fabs(dx) < (this->width_/2 + com->width_/2) && fabs(dy) < (this->height_/2 + com->height_/2))
    {

        //Interserctan

        
        return true;

    }

    return false;
}


void CollisionComponent::checkCollision(GameObject *obj)
{

    CollisionComponent *com = obj->getComponent<CollisionComponent>();

    if(testCollision(com)){

        std::cout<<"Colisiona \n";







    }




}