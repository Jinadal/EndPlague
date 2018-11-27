#pragma once

#include "../Component.h"

class MoveComponent : public Component{

    public:

        //Constructor
        MoveComponent(GameObject *owner) : Component(owner){}

        //Destructor
        ~MoveComponent(){}

        //Init
        void Init();

        //Update
        void Update(float , float);

        //Close
        void Close();

    private:

        float vMax, vX, vY, vZ, preX, preY, preZ;

};