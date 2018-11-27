#include <LifeComponent.h>

void LifeComponent::looseLife(float d){     //Gets by parametre a int damage from the attacker
    setLife(life - d);                      //Sets decreased life
}
