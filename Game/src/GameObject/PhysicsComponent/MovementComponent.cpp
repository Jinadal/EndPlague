#include "MovementComponent.h"
#include "GameObject.h"
#include <iostream>
#include <cmath>

void MovementComponent::update(){
    /* El sistema de movimiento esta pensado para que en cada ciclo del juego se comprueben
    todas las teclas, si W esta pulsada debe mandar un 1, si D esta pulsada debe mandar un 2,
    si S esta pulsada debe mandar un 3, si A esta pulsada debe mandar un 4. Este componente
    no va a dibujar nada, solo va a modificar la posicion del objeto para que se dibuje en la
    siguiente iteracion.
    Falta incluir de forma funcional la aceleracion para cuando el personaje empieza a andar,
    pero deberia ser de forma que el input utilice un booleano para determinar si se esta moviendo
    o no. A lo que aun no he llegado es a como saber si el personaje se ha detenido para volver a
    bajarle la velocidad, ya que puede haber levantado una tecla pero estar pulsando otra, por lo
    que la aceleracion ya se ha aplicado y la velocidad es maxima.
    En la anterior rama tengo las formulas aplicadas con la aceleracion maxima y la estructura que habia
    hecho (mucho mas comoda que llamar a x, y, z cada vez) pero contaba con que usariamos los vectores
    de Irrlicht y una variable de tiempo (tenemos que ver como gestionamos el tiempo en nuestro juego).
    El codigo mas basico y que en principio funciona es este. */


    //Comprobar vMax
    float length = Math.sqrt(Math.pow(vX, 2) + Math.pow(xY, 2));
    vX = (vX/length)*vMax;
    vY = (vY/length)*vMax;

    float rz = Math.sin(vY/vX);

    preX=gameObject->getX();
    preY=gameObject->getY();
    preZ=gameObject->getZ();

    gameObject->setX(gameObject->getX() + vX);
    gameObject->setY(gameObject->getY() + vY);
    gameObject->setZ(gameObject->getZ() + vZ);

    gameObject->setRZ(rz);
}

void MovementComponent::goBackX(){
    gameObject->setX(preX);
}

void MovementComponent::goBackY(){
    gameObject->setY(preY);
}


void MovementComponent::moveObject(int x, int y){
    if(x<0)
        this->vX = -1;
    else if(x==0)
        this->vX = 0;
    else if(x>0)
        this->vX = 1;

    if(y<0)
        this->vY = -1;
    else if(y==0)
        this->vY = 0;
    else if(y>0)
        this->vY = 1;

}