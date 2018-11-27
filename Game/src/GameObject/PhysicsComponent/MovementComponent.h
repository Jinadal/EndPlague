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

    private:

        float vMax, vX, vY, vZ, preX, preY, preZ;

};