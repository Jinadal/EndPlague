#pragma once
#include "Component.h"
#include "GameObject.h"

class Manager;
class MovementComponent : public Component{
    private:
        float vMax, vX, vY, vZ, rZ, preX, preY, preZ;

    public:

        //Constructor
        MovementComponent(GameObject *g, Manager* m) : Component(g, m){
            vX      = 0.f;
            vY      = 0.f;
            vZ      = 0.f;
            rZ      = 0.f;
            vMax    = 40.f;
            preX    = 0.f;
            preY    = 0.f;
            preZ    = 0.f;
        }

        //Destructor
        virtual ~MovementComponent(){}

        //Update
        void update(float dt);

        //Close
        void close();

        //Input
        void moveObject(int x, int y, float tx, float ty);

        //GoBack
        void goBackX();
        void goBackY();

        
        //Getters
        float getvMax(){return vMax;}
        float getvX(){return vX;}
        float getvY(){return vY;}
        float getvZ(){return vZ;}

        //Setters
        void setvMax(float v){vMax = v;}
        void setvX(float v){vX = v;}
        void setvY(float v){vY = v;}
        void setvZ(float v){vZ = v;}
};