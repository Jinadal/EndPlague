#include <iostream>
class GameObject;
class Fabric
{
    public:
        Fabric(){}
        virtual ~Fabric(){}

        virtual void loadLevel() = 0;
        virtual bool playerAlive(){
            bool r=true;
            std::cout<<player<<"\n";
            if(player==nullptr)
            {
                r=false;
            } 
            
            return r;
        };
    protected:
        GameObject* player;
};