#include "LevelLoader.h"



Level level2 = {
    "res/Mapa1.obj",//Map OBJ
    "res/mapapeque.bmp",//Map BMP
    "res/bullet/Mapa01.bullet",//Map BULLET

    -11.f,//Player x
    -17.f,//Player y
    -2.f,//Player z

    //Spawns
    {{-5.f, 3.f, 90.f, true},
    {-11.f, 15.f, 180.f, true}},

    //Wells
    {},

    //Waypoints
    {{4.7,-14},
    {8,-12.4},
    {10,1.5},
    {2,-3},
    {-11,0},
    {-9,9},
    {-3,12},
    {11,13},
    },

    //Area

    {{-12, -15,7,-20},
    {2,-11,8,-15},
    {-12,-1,2,-5},
    {9,1,11,-14},
    {-6,7,12,1},
    {-12,17,-9,0},
    {-4,17,-1,13},
    {-8,12,11,5},
    {9,18,11,13}
    },

    //WaypointToArea

    {{0,0},
    {0,1},
    {1,1},
    {1,3},
    {2,3},
    {2,4},
    {3,1},
    {3,2},
    {4,2},
    {4,5},
    {5,5},
    {5,7},
    {6,6},
    {6,7},
    {7,8},
    {7,7}
    },

    //ConexToGraph
    {{0,1},
    {1,2},
    {1,3},
    {3,4},
    {4,5},
    {5,6},
    {6,7},
    },
    //Patrulla

    {{4,{-1, 4, 7, 5 }},
    {5,{-11, -4, -11, 10 }}
  
    }
};