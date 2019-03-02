#pragma once

namespace gv
{

//###########################################
//~~~~~~~~~~~~~~~~ ENGINE ~~~~~~~~~~~~~~~~~~~
//###########################################

    //----------   CLOCK    ------------
        const int CLOCK_FPS = 60;

    //---------- INTRO STATE------------
        const float INTRO_DURATION = .1f; //seg

    //----------   CAMERA   ------------
        const float CAMERA_MIN_ZOOM = .8f;
        const float CAMERA_MAX_ZOOM = 10.2f;
        const float CAMERA_ZOOM_VEL = .105f;

        const float CAMERA_DY = 5.f;  //Y distance
        const float CAMERA_DZ = 10.f; //Z distance

        const float CAMERA_VELOCITY = 10.f;

    //------------- PHYSICS --------------
        const float PHYSICS_GRAVITY = 9.8f;
        const float PHYSICS_VELOCITY = 50.f;


//###########################################
//~~~~~~~~~~~~~~~~ PLAYER ~~~~~~~~~~~~~~~~~~~
//###########################################

        const float PLAYER_LIFE_DECREASE = 2.f;

//###########################################
//~~~~~~~~~~~~~~~~ WEAPONS ~~~~~~~~~~~~~~~~~~
//###########################################

    //---------- POTION ------------
        const float POTION_VALUE = 50.f;   
    
    //---------- SHIELD ------------
        const float SHIELD_VALUE = 400.f;

    //---------- CROSSBOW ------------
        const float CROSSBOW_CADENCE = .1f;
    
    //------------ PEAK --------------
        const float PEAK_CADENCE = .5f;

    //------------- AXE --------------
        const float AXE_CADENCE = .8f;



//###########################################
//~~~~~~~~~~~~~~~~~ ENEMIES ~~~~~~~~~~~~~~~~~~
//###########################################

    //-------- DROP PROBABILTY ----------
        const int DROP_P_POTION      = 30;
        const int DROP_P_AXE         = 35;
        const int DROP_P_PEAK        = 40;
        const int DROP_P_CROSSBOW    = 50;
        const int DROP_P_SHIELD      = 80;

    
    //----------- ENEMY 1 ---------------
    const float ENEMY_1_LIFE = 200.f;
    const float ENEMY_1_VELOCITY = 3.f;

    //----------- ENEMY 2 ---------------
    const float ENEMY_2_LIFE = 100.f;
    const float ENEMY_2_VELOCITY = 3.f;

    const int ENEMY_SCORE = 10;
    const float ENEMY_CADENCE = .9f;
    const int ENEMY_WEAPON = 2; // 1:AXE 2:PEAK 3:ARROW??



//###########################################
//~~~~~~~~~~~~~~~~~ SPAWNS ~~~~~~~~~~~~~~~~~~
//###########################################

    const float     SPAWN_CADENCIA      = 3.f;
    const int       MAX_ENEMIES         = 80;

    //---------- WOOD AND FIRE -----------
    const float     FIRE_DAMMAGE        = 10.f;
    const int       BUCKETS_NEDED       = 5;

} // gv
