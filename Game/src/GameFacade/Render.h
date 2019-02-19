#pragma once


class Render{
    private:
    public:
        
        static Render* getInstance()
        
        void setCamera()

        //Draws all the scene, better at the end of loop
        void drawAll();
        //Returns true if cotinues the loo
        bool run();
        //Closes the device
        void drop();
        //Returns the time betwen las loop and now
        float getFrameDeltaTime();
        float getCursorX();
        float getCursorY();
        void isMap(){map=node;}
};