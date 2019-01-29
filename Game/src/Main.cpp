#include "Game.h"
#include "Waypoint.h"
#include <iostream>
int main(){
    
   // Game::getInstance()->run();

    GPS* gps = new GPS();
    gps->Initialice();

    std::vector<float> f = gps->getWay(1,11,11,1);

    std::cout << "RUTA : \n";

    for(std::size_t i = 0; i<f.size()-1; i=i+2)
    {
        std::cout<<"     Coor: "<<f[i]<<" - "<<f[i+1]<<"\n";
    }

    return 0;
}