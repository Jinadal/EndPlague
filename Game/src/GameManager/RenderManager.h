#include "RenderComponent.h"

class RenderManager{
    private:
        std::vector<RenderComponent*> components;
    public:
        RenderManager(){}

        ~RenderManager(){}

        void addComponent(RenderComponent* rc){
            components.push_back(rc);
        }

        void updateAll(){
            for(auto& c components){
                c->update();
            }
        }
};