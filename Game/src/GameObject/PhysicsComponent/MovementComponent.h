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

    private:

        float vMax, vX, vY, vZ, preX, preY, preZ;

};