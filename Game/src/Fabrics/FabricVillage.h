#include "Fabric.h"
#include <vector>

class FabricVillage : public Fabric{
    private:
        
    public:
        FabricVillage():Fabric(){}
        ~FabricVillage(){}

        void loadLevel();
};

class BuildtRecord
{
     private:
        static BuildtRecord* only_instance ;
        BuildtRecord(){}
        std::vector<GameObject*> spawns;
        std::vector<GameObject*> pozos;

    
    public:
        ~BuildtRecord(){ only_instance = nullptr;}
        static BuildtRecord* getInstance()
        {
            if(!only_instance)
                only_instance = new BuildtRecord();

            return only_instance;
        }

        std::vector<GameObject*> getSpawns(){return spawns;}
        std::vector<GameObject*> getPozos(){return pozos;}

        void addSpawn(GameObject* spawn){spawns.push_back(spawn);}
        void addPozo(GameObject* pozo){pozos.push_back(pozo);}

       
      
};