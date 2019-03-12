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

        bool hasNext();
        void loadNext();
        void createMap(char* obj, char* bmp, char* bullet);
        void createPlayer(float x, float y, float rz);
        void createSpawn(float x, float y, float rz, bool type);
        void createWell(float x, float y, float rz);
        GameObject* getPlayer(){return player;}
        void writeFile();
};


struct xyrt
{
    float x, y, r;
    bool t;
};


struct Level
{
    //NewValues
    //Mapa
    char map_obj[20], map_bmp[20], map_bullet[20];
    //Player
    float pla_x, pla_y, pla_rz;
    //Spawns
    std::vector<xyrt> spawns;
    //Wells
    std::vector<xyrt> wells;

    //GPS
};

