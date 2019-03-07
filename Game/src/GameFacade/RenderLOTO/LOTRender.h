#pragma once
#include "FRender.h"

class LOTRender : public FRender{
    private:
        LOTRender();
    public:
        
        static LOTRender* getInstance(){
            static LOTRender only_instance;
            return &only_instance;
        }
        
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//---------- - - - - - - COMMON FUNCTIONS - - - - - - - - - ----------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------          

        void drawAll();
        bool run();
        void drop();
        float getCursorX();
        float getCursorY();
        FMesh* createMesh(char* s);
        FCamera* createCamera();
        FHUD* getHUD();
        FMenu* getMenu();
};