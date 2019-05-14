#include "LevelLoader.h"


Level village = {
    "res/obj/SUELO.obj",//Map OBJ
    "res/obj/Suelo.bmp",//Map BMP
    "res/bullet/Mapa_2.bullet",//Map BULLET

    -40.f,//Player x
    -46.f,//Player y
    -1.f,//Player z

    //Spawns
    {
    {-24.7f, -46.1f, 0.f, false},
    {-1.1f, -45.7f, 90.f, true},
    {45.8f, -46.0f, 270.f, true},
    {14.9f, -39.0f, 180.f, false},
    {-10.5f, -34.7f, 0.f, true},
    {14.8f, -31.4f, 0.f, true},
    {31.3f, -26.f, 270.f, true},
    {-32.f, -22.6f, 270.f, true},
    {-24.f, -14.2f, 180.f, false},
    {-17.6f, -14.f, 90.f, true},
    {15.1f, -13.7f, 180.f, true},
    {45.7f, -14.2f, 270.f, true},
    {-0.9f, -5.6f, 270.f, true},
    {8.2f, -4.6f, 0.f, true},
    {27.6f, -5.7f, 90.f, true},
    {-45.6f, 4.f, 90.f, true},
    {-0.4f, 8.4f, 270.f, false},
    {19.7f, 16.f, 270.f, false},
    {27.9f, 16.7f, 90.f, true},
    {28.2f, 23.8f, 0.f, true},
    {38.f, 23.5f, 90.f, true},
    {-4.7f, 30.7f, 270.f, true},
    {-32.f, 45.5f, 180.f, true},
    {-24.f, 45.f, 180.f, false},
    {20.3f, 44.6f, 270.f, true},
    {27.6f, 45.6f, 180.f, false},
    {45.6f, 45.9f, 180.f, false}
    },

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
    {37.9f, 46.4f, 0.f, true}}
};