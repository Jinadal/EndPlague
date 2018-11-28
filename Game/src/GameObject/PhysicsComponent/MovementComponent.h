#pragma once
#include "Component.h"
#include "GameObject.h"


class MovementComponent : public Component{

    public:

        //Constructor
        MovementComponent(GameObject *g);

        //Destructor
        ~MovementComponent(){}

        //Update
        void update(float dt);

        //Close
        void close();

        //Input
        void moveObject(int x, int y);

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

    private:

        float vMax, vX, vY, vZ, preX, preY, preZ;

};