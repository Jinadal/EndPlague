#pragma once
#include "FMenu.h"

class TBillboard;
class KATMenu : public FMenu
{
    private:
        TBillboard* background;
        KATMenu() : FMenu(){};
    public:

        static KATMenu* getInstance(){
            static KATMenu only_instance;
            return &only_instance;
        }
        


        ~KATMenu() {}
        void setMenuBackground(char* t);
        void clearBackground();
        void update(){}
};