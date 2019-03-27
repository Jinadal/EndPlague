#pragma once
#include <vector>

namespace gv
{

//########################################################################
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ENGINE ~~~~~~~~~~~~~~~~~~~
//########################################################################

    //----------   CLOCK    ------------
        const int       CLOCK_FPS               = 100;   //FPS

    //---------- INTRO STATE------------
        const float     INTRO_DURATION          = .1f;  //seg

    //----------   CAMERA   ------------
        const float     CAMERA_MIN_ZOOM         = .8f;
        const float     CAMERA_MAX_ZOOM         = 10.2f;
        const float     CAMERA_ZOOM_VEL         = .05f;  //Velocity of camera zoom

        const float     CAMERA_DY               = 5.f;  //Camera Y distance
        const float     CAMERA_DZ               = 10.f; //Camera Z distance

        const float     CAMERA_VELOCITY         = 10.f; //Velocity of camera movement

    //------------- PHYSICS --------------
        const float     PHYSICS_GRAVITY         = 50.f;   //All general gravity  9.8f
        const float     PROJECTILE_GRAVITY      = 1.f;      //ONLY projectiles gravity 0.f
        const float     PHYSICS_VELOCITY        = 80.f;     //Multiplies the time of phisics 50.f

    //------------- RENDER  --------------
        const bool      RENDER_ENGINE           = true;     //If true Irrlicht, else LOTTO
        const unsigned int SCR_WIDTH            = 1366;
        const unsigned int SCR_HEIGHT           = 768;


    //-------------- SOUND --------------
        const int MIN_ENEMIES_FOR_ACTION        = 5;
    


//########################################################################
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ PLAYER ~~~~~~~~~~~~~~~~~~~
//########################################################################

        const float     PLAYER_LIFE_DECREASE    = 2.f;      //Units per sec life decrease
        const float     PLAYER_VELOCITY         = 7.f;      //Movement velovity of player
        const float     PLAYER_LIFE             = 1000.f;   //Player life
        const float     PLAYER_STRT_CADENCE     = 0.5;      //First weapon cadence
        const int       PLAYER_STRT_WEAPON      = 1;        //First weapon






//########################################################################
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ WEAPONS ~~~~~~~~~~~~~~~~~~
//########################################################################

    //---------- POTION ------------
        const float     POTION_VALUE        = 50.f;   //Units of life potion add
    
    //---------- SHIELD ------------
        const float     SHIELD_VALUE        = 400.f;  //Units of shield

    //---------- CROSSBOW ------------
        const float     CROSSBOW_CADENCE    = .1f;
        const float     ARROW_VELOCITY      = 10.f;
        const float     ARROW_DAMAGE        = 10.f;
    
    //------------ PEAK --------------
        const float     PEAK_CADENCE        = .5f;
        const float     PEAK_VELOCITY       = 10.f;
        const float     PEAK_DAMAGE         = 50.f;


    //------------- AXE --------------
        const float     AXE_CADENCE         = .8f;
        const float     AXE_VELOCITY        = 10.f;
        const float     AXE_DAMAGE          = 50.f;






//######################################################################
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ENEMIES ~~~~~~~~~~~~~~~~~~
//######################################################################

    //-------- DROP PROBABILTY ----------
        const int       DROP_P_POTION       = 30;
        const int       DROP_P_AXE          = 35;
        const int       DROP_P_PEAK         = 40;
        const int       DROP_P_CROSSBOW     = 50;
        const int       DROP_P_SHIELD       = 80;

    
    //----------- ENEMY 1 ---------------
        const float     ENEMY_1_LIFE        = 200.f;
        const float     ENEMY_1_VELOCITY    = 4.f;

    //----------- ENEMY 2 ---------------
        const float     ENEMY_2_LIFE        = 100.f;
        const float     ENEMY_2_VELOCITY    = 4.f;

        const int       ENEMY_SCORE         = 10;  //Score gets killing as enemy
        const float     ENEMY_CADENCE       = .9f; //Shoot cadence of enemies
        const int       ENEMY_WEAPON        = 2;   //1:AXE 2:PEAK 3:ARROW??






//#####################################################################
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SPAWNS ~~~~~~~~~~~~~~~~~~
//#####################################################################

    const float     SPAWN_CADENCIA          = 3.f;
    const int       MAX_ENEMIES             = 80;  //NOT USED
    const int       MIN_ENEMIES             = 20;  
    const int       ENEMIES_PER_SPAWN       = 4;


    //---------- WOOD AND FIRE -----------
    const float     FIRE_DAMMAGE            = 10.f;
    const int       BUCKETS_NEDED           = 5;
    const float     SPAWN_LIFE              = 400.f;

}
