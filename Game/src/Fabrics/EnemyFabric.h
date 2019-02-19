#pragma once

class GameObject;

#define MAX_ENEMIES 20


enum EnemyType
{
    ENEMY_1,
    ENEMY_2
};

struct EType{
    EnemyType type;
    char* mesh;
    char* texture;
    float life;
    float vMax;
};

class EnemyFabric
{
    private:
        EType enemytypes [2] = 
        {
            {
                ENEMY_1,
                (char*)"res/DOOMIE.obj",
                (char*)"res/red.bmp",
                200.f,
                10.f  //Velocidad media andando
            },
            {
                ENEMY_2,
                (char*)"res/DOOMIE.obj",
                (char*)"res/green.bmp",
                100.f,
                10.f
            },
        };


        int numEnemies;

    public:
        EnemyFabric(){numEnemies = 0;}
        virtual ~EnemyFabric(){}

        GameObject* createEnemy(float x, float y, float z, float rz, EnemyType type);
        int getNumEnemies(){return numEnemies;}
};