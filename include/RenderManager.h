#pragma once

//Headers
#include "RenderComponent.h"
#include <vector>


class RenderManager{
  public:
    //Constructor
    RenderManager(RenderFacade*  rf){
      renderFacade = rf;
    }

    void addComponent(RenderComponent* c);
    void update();
    void init();
    void run();
  }
  private:
    std::vector<RenderComponent*> components;
    RenderFacade* renderFacade;
};