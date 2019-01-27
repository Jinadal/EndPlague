#include "RenderIrrlicht.h"

class RenderStaticText
{
    private:
        IGUIStaticText* enemies;
        IGUIStaticText* fps;
        IGUIStaticText* life;
        IGUIStaticText* score;
    
    public:
        RenderStaticText()
        {
            enemies = RenderIrrlicht::getInstance()->getGUIEnv()->addStaticText(L"Enemies loaded: ", core::rect<s32>(10,10,100,20), true, false, 0, 0, true);
            fps = RenderIrrlicht::getInstance()->getGUIEnv()->addStaticText(L"FPS: ", core::rect<s32>(10,20,100,30), true, false, 0, 0, true);
            life = RenderIrrlicht::getInstance()->getGUIEnv()->addStaticText(L"Life: ", core::rect<s32>(10,30,100,40), true, false, 0, 0, true);
            score = RenderIrrlicht::getInstance()->getGUIEnv()->addStaticText(L"Score: ", core::rect<s32>(10,40,100,50), true, false, 0, 0, true);

        }

        ~RenderStaticText()
        {
            life->remove();
            enemies->remove();
            fps->remove();
            score->remove();
        }

        void updateValues(int enemies, int fps, float life, int score)
        {
            std::cout<<enemies<<" "<<fps<<" "<<life<<" "<<score<<"\n";


            wchar_t* text = L"Enemies loaded: ";
            this->enemies->setText(text);

            text = L"FPS: ";
            this->fps->setText(text);

            text = L"Life: ";
            this->life->setText(text);

            text = L"Score: ";
            this->score->setText(text);
        }

};