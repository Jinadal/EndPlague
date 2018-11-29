
#include "CollisionComponent.h"
#include <vector>

class LifeComponent;
class ProjectileComponent;
class CollisionManager
{
   private:
    //Constructor
    CollisionManager(){}
    static CollisionManager* only_instance;
    std::vector<CollisionComponent*> components;

    //bool testCollision(CollisionComponent *com1, CollisionComponent *com2 );


  public:

    static CollisionManager *getInstance(){         //Pattern Singleton
        if(only_instance == NULL)
            only_instance = new CollisionManager();
        
        return only_instance;
    }
  

    virtual ~CollisionManager(){}

    void createComponent(GameObject *owner, float width, float height,bool solid);

    void removecomponent(Component* c);    
    
    void update();

    int conMove = 0;
};