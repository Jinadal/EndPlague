#include "WoodManager.h"
#include "LifeComponent.h"
#include "GameResource.h"
#include "GameObject.h"
#include "ScoreManager.h"
class HUD
{
    private:
        //HUDFacade* facade = new HUDFacade();

        int spawnsCount;
        float life;
        int score;
        bool berseck;
        bool terrify;
    public:
        HUD(){}
        ~HUD(){
            //delete facade;
        }
        void update();
};