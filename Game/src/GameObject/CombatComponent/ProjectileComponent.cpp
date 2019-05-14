#include "ProjectileComponent.h"
#include "LifeComponent.h"
#include "GameObject.h"
#include "SpecificSoundEvent.h"

void ProjectileComponent::dealDamage(LifeComponent* l){
    if(l && l->getTeam()!=team)
        l->looseLife(damage);

    if(team==2)
    {
        
        EnemyHurtsSoundEvent* s = new EnemyHurtsSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("ehit"));
        s->setVoiceParameter();
        s->setPosition({gameObject->getX(),gameObject->getY(),gameObject->getZ()});
        s->setVolume(5);
        s->start();

        delete s;
    }
        
    gameObject->setKill(true);
}
