#pragma once
class GameObject;
class Fabric
{
    protected:
        GameObject* player;
    public:
        Fabric(){}
        virtual ~Fabric(){}

        virtual void loadLevel() = 0;
        GameObject* getPlayer(){return player;}
 
};
