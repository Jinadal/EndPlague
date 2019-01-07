#include "RenderIrrlicht.h"






// Declare a structure to hold some context for the event receiver so that it
// has it available inside its OnEvent() method.
struct SAppContext
{
    IrrlichtDevice *device;
    s32             counter;
    IGUIListBox*    listbox;
};


enum
{
    GUI_PLAY_BUTTON,
    GUI_EXIT_BUTTON
};


class MyEventReceiver : public IEventReceiver
{
public:
    MyEventReceiver(SAppContext & context) : Context(context) { }

    virtual bool OnEvent(const SEvent& event)
    {
        if (event.EventType == EET_GUI_EVENT)
        {
            s32 id = event.GUIEvent.Caller->getID();
            
            if(event.GUIEvent.EventType == EGET_BUTTON_CLICKED)
            {
                switch(id)
                {
                    case GUI_PLAY_BUTTON:
                        return true;

                    case GUI_EXIT_BUTTON:
                        return true;

                    default:
                        return true;
                }
            }
        }
        return false;
    }

private:
    SAppContext & Context;
};



class Menus
{
    private:

    public:
        Menus(){}
        ~Menus(){}

        int loadStartMenu();
        int loadEndMenu();
};