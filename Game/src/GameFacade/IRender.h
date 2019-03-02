class MeshNode;
class CameraNode;
class IRender
{
    public:
        //Draws all the scene, better at the end of loop
        virtual void drawAll() = 0;

        //Returns true if cotinues the loop
        virtual bool run() = 0;

        //Closes the device
        virtual void drop() = 0;

        //Returns the position x, y of the cursor
        virtual float getCursorX() = 0;
        virtual float getCursorY() = 0;

        //Creates mesh and camera
        virtual MeshNode* createMesh(char* s) = 0;
        virtual CameraNode* createCamera() = 0;
};