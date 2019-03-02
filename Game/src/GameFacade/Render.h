#pragma once
#include "RenderIrrlicht.h"

const int renderType = 0;
class Render{
    private:
        IRender* render;
        Render()
        {
            if(renderType == 0)
            {
                render = RenderIrrlicht::getInstance();
            }else
            {
                //render = RenderLotus::getInstance();
            }
        }
    public:
        
        static Render* getInstance(){
            static Render only_instance;
            return &only_instance;
        }
        
        //Draws all the scene, better at the end of loop
        void drawAll(){render->drawAll();}

        //Returns true if cotinues the loop
        bool run(){return render->run();}

        //Closes the device
        void drop(){render->drop();}

        //Returns the position x, y of the cursor
        float getCursorX(){return render->getCursorX();}
        float getCursorY(){return render->getCursorY();}

        //Creates mesh and camera
        MeshNode* createMesh(char* s){return render->createMesh(s);}
        CameraNode* createCamera(){return render->createCamera();}

};