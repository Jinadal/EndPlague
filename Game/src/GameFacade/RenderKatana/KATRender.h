#pragma once
#include "FRender.h"
#include "Katana.h"


class KATRender : public FRender{
    private:
        Katana* katana;
        KATRender();
    public:
        
        static KATRender* getInstance(){
            static KATRender only_instance;
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