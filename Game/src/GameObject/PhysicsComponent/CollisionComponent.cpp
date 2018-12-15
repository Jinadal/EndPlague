#include "CollisionComponent.h"

#include <cmath>

#include <iostream>

//Se le pasa el componente de colision del objeto con el que queremos comprobar la colision
//Si intersectan, entoces es que se ha dado y se devuelve true

bool CollisionComponent::testCollision(CollisionComponent *com)
{

    //Recojo los GameObjects, de este componente y del que me pasan
    GameObject *obj1 = this->getGameObject();
    GameObject *obj2 = com->getGameObject();


    //Diferencia entre las posiciones x e y de los dos objetos, el que me pasan menos en el que estoy

    /*
        dx = x2 - x1
        dy = y2 - y1
    */
    float dx = obj2->getX() - obj1->getX();
    float dy = obj2->getY() - obj1->getY();

    //si abs(dif en X) es menor que la suma del punto medio de las anchuras, es decir, que la distancia entre las x sea menor que la suma de los puntos medios,
    // y lo mismo pero para la diferencia en Y y las alturas, es que los objeton intersectan entre sí

    /*
        [dx] < w1/2 + w2/2 
                &&
        [dy] < h1/2 + h2/2

    */
    if(fabs(dx) < (this->width_/2 + com->width_/2) && fabs(dy) < (this->height_/2 + com->height_/2))
    {

        //Interserctan

        
        return true;

    }

    return false;
}