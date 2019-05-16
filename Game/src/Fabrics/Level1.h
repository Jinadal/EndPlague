#include "LevelLoader.h"


Level level1 = {
    "res/Mapa2.obj",//Map OBJ
    "res/obj/Suelo.bmp",//Map BMP
    "res/bullet/Mapa_2.bullet",//Map BULLET

    0.f,//Player x
    0.f,//Player y
    -1.f,//Player z

    //Spawns
    {{-24.7f, -46.1f, 0.f, false}},

    //Wells
    {{13.f, 1.7f, 0.f, true},
    {19.3f, 29.8f, 0.f, true},
    {-3.6f, -27.5f, 0.f, true},
    {-17.5f, -44.5f, 0.f, true},
    {-19.5f, -18.5f, 0.f, true},
    {31.2f, -20.7f, 0.f, true},
    {29.8f, -37.5f, 0.f, true},
    {45.8f, -7.5f, 0.f, true},
    {39.1f, 17.3f, 0.f, true},
    {26.9f, 33.4f, 0.f, true},
    {46.7f, 34.3f, 0.f, true},
    {37.9f, 46.4f, 0.f, true}
    },

    //Waypoints
    {{-38.7 ,-26},
    {-28,1},
    {-33,15.7},
    {-28,28},
    {12.9,12.5},
    {20.9,-9.8},
    {11.4,-22.7},
    {4.6,-34.9},
    {11.5,-47},
    {28.8,-14.6},
    {36.7,-9.8},
    {46.7,-35.54},
    {46.8,19.9}
    },

    //Area

    {{-49,-26, -28, -49},
    {-49,49, -28, -26},
    {-28,49, 24, 13},
    {-28,13, 3, -10},
    {-28,-10, 11, -49},
    {3,13, 24, -10},
    {24,49, 49, 19},
    {24,20, 49, -10},
    {11,-10, 49, -35},
    {11,-35, 49, -49}
    },

    //WaypointToArea

    {{0,1},
    {1,0},
    {1,1},
    {1,2},
    {1,3},
    {2,3},
    {2,4},
    {3,1},
    {4,6},
    {4,7},
    {4,8},
    {5,4},
    {5,5},
    {6,12},
    {7,10},
    {7,12},
    {8,5},
    {8,6},
    {8,9},
    {8,10},
    {8,11},
    {9,8},
    {9,11}
    },

    //ConexToGraph
    {{0,1},
    {0,3},
    {1,2},
    {2,3},
    {3,4},
    {4,5},
    {5,6},
    {5,9},
    {5,11},
    {6,10},
    {6,11},
    {6,7},
    {7,8},
    {8,11},
    {9,10},
    {10,11},
    {10,12}
    },
    //Patrulla

    {{0,{-45, 10, -35, -20 }},
    {1,{-43, 35, -34, 35, -36,18, -34,4, -36, 10  }},
    {2,{-19, 21, 5, 20, 8,31, -4,44, -19,40 } },
    {3,{-7, 1, -16, -5, -23,1 }},
    {4,{6, -39, 4, -21 ,-11,-23,-20,-29,-17,-40,-2,-38 }},
    {5,{12, 7, 19, 1, 16,-4 }},
    {6, {45,27, 39, 40, 32,31 }},
    {7,{46,-1, 45,10,33,9,30,2 }},
    {8,{21, -22,24,-31, 42,-30, 39,-20 } },
    {9,{37, -40, 24, -40, 24,-47 }}
    }
};