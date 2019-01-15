#include "BPhysicManager.h"
#include "IAComponent.h"
#include "ProjectileComponent.h"
#include "LifeComponent.h"
#include "StorageComponent.h"
#include "ItemComponent.h"
#include "InputComponent.h"

BPhysicManager* BPhysicManager::only_instance = NULL;

void BPhysicManager::createComponent(GameObject* owner, float xsize, float ysize, float zsize, float mass, int physicType)
{
    components.push_back(new BPhysicComponent(owner, this, xsize, ysize, zsize, mass, physicType));
    owner->addComponent(components[components.size()-1]);
}


void BPhysicManager::updateAll(float dt){
    for(std::size_t i = 0; i<components.size(); i++)
    {
        ((BPhysicComponent*)components[i])->update();
    }
    PhysicBullet::getInstance()->iteration(dt);
}
//Callback which registers and shows in terminal the colliding objects
//Parametres are standars of the bullet engine, no need of thinking much about them
//Need to add the next to lines to main or world init

//Allows to make a callback in another directory
//gContactAddedCallback = <nameofcollisionmanager>p->callbackFunc;
bool BPhysicManager::callbackFunc(btManifoldPoint& cp, const btCollisionObjectWrapper* obj1, int id1, int index1, const btCollisionObjectWrapper* obj2, int id2, int index2)
{
    GameObject* go1 = (GameObject*)obj1->getCollisionObject()->getUserPointer();
    GameObject* go2 = (GameObject*)obj2->getCollisionObject()->getUserPointer();

    if(go1->getKill() || go2->getKill())
        return false;

    IAComponent* i_IA = go1->getComponent<IAComponent>();

    if(i_IA)
    {
        InputComponent* j_input = go2->getComponent<InputComponent>();

        if(!j_input)
            i_IA->didIcollide = true;   
    }

    //SpawnComponent* i_SP = go1->getComponent<SpawnComponent>();
    //if(i_SP)
    //{
    //    IAComponent* j_IA = go2->getComponent<IAComponent>();
    //    if(j_IA)
    //        j_IA->didIcollide = true;

    //}

    
    ProjectileComponent* i_projectil = go1->getComponent<ProjectileComponent>();
    ProjectileComponent* j_projectil = go2->getComponent<ProjectileComponent>();

    LifeComponent* i_life = go1->getComponent<LifeComponent>();
    LifeComponent* j_life = go2->getComponent<LifeComponent>();

    if(i_projectil)
        i_projectil->dealDamage(j_life);
    if(j_projectil)
        j_projectil->dealDamage(i_life);


    //En el caso de que lo que colisione sea un item
    StorageComponent* i_storage = go1->getComponent<StorageComponent>();
    StorageComponent* j_storage = go2->getComponent<StorageComponent>();

    ItemComponent* i_item   = go1->getComponent<ItemComponent>();
    ItemComponent* j_item   = go2->getComponent<ItemComponent>();

    if(i_storage && j_item) //Si i es un item
        i_storage->itemCatch(j_item);

    if(j_storage && i_item) //Si i es un item
        j_storage->itemCatch(i_item);

    return false;
}