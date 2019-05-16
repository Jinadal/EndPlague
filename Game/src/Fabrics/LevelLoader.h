#pragma once
#include "GameValues.h"
#include <vector>
class GameObject;
class LevelLoader
{
    private:
        LevelLoader(){};
        std::size_t next = 0;
        GameObject* player;
    public:
        static LevelLoader* getInstance()
        {
            static LevelLoader only_instance;
            return &only_instance;
        }

        ~LevelLoader(){};

        void resetNext(){next=0;};
        bool hasNext();
        void loadLevel();
        void createMap(char* obj, char* bmp, char* bullet);
        void createPlayer(float x, float y, float rz);
        void createSpawn(float x, float y, float rz, bool type);
        void createWell(float x, float y, float rz);
        GameObject* getPlayer(){return player;}
        void writeFile();

        
        void assignPatrulla(float a, std::vector<float> p);

};


struct xyrt
{
    float x, y, r;
    bool t;
};

struct pat
{
    float a;
    std::vector<float> p;

};


struct Level
{
    //NewValues
    //Mapa
    char map_obj[30], map_bmp[30], map_bullet[30];
    //Player
    float pla_x, pla_y, pla_z;
    //Spawns
    std::vector<xyrt> spawns;
    //Wells
    std::vector<xyrt> wells;

    //GPS

    //patrulla 
    std::vector<pat> patrulla;
};

