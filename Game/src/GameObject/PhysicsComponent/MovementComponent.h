#pragma once

#include "Component.h"

class MovementComponent : public Component{

    public:

        //Constructor
        MovementComponent(GameObject *owner) : Component(owner){}

        //Destructor
        ~MovementComponent(){}

        //Init
        void Init();

        //Update
        void Update(float , float);

        //Close
        void Close();

        //Input
        void moveObject(int x, int y);

        //GoBack
        void GoBackX();
        void GoBackY();

        
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