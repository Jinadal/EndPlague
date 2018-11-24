#pragma once
#include "RenderComponent.h"
#include <vector>

class RenderManager{
    private:
        std::vector<RenderComponent*> components;
    public:
        RenderManager(){}

        ~RenderManager(){}

        void addComponent(RenderComponent* rc);
        void updateAll();
};