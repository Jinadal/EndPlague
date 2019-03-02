#include "RenderIrrlicht.h"
#include "MeshNode.h"
#include "CameraNode.h"


RenderIrrlicht::RenderIrrlicht(){
    //We need to use video::EDT_SOFTWARE!!
    //BUT we only can see the map with EDT:OPENGL!
    device = createDevice( video::EDT_OPENGL, dimension2d<u32>(1366, 768), 16,
			false, false, false, 0);

    if (!device)
        return;

    device->setWindowCaption(L"Screams In Goblin");
    
    device->getLogger()->setLogLevel(ELL_ERROR);

    driver = device->getVideoDriver();
    smgr = device->getSceneManager();
    guienv = device->getGUIEnvironment();

    smgr->addLightSceneNode(0, core::vector3df(10,0,-100),
    video::SColorf(1.0f,1.0f,1.0f,1.0f), 1000.0f);
}


void RenderIrrlicht::drawAll()
{
    driver->beginScene(true, true, SColor(255,100,100,100));

    smgr->drawAll();
    guienv->drawAll();

    driver->endScene();
}

bool RenderIrrlicht::run()
{
    return device->run();
}

void RenderIrrlicht::drop()
{
    device->drop();
}


float RenderIrrlicht::getCursorX()
{
    if(!map)
        return 0.f;

    ITriangleSelector*  selector=smgr->createTriangleSelector(map->getMesh(), map);
    core::vector3df     outCollisionPoint;
    core::triangle3df   outTriangle;
    ISceneNode*         outNode=nullptr;

    ISceneCollisionManager* colmgr = smgr->getSceneCollisionManager();
    line3d<float> raytrace = colmgr->getRayFromScreenCoordinates(device->getCursorControl()->getPosition(), camera);
    colmgr->getCollisionPoint(	raytrace,
                                selector,
                                outCollisionPoint,
                                outTriangle,
                                outNode
                                );

    selector->drop();
    return outCollisionPoint.X;
}

float RenderIrrlicht::getCursorY()
{
    if(!map)
        return 0.f;

    ITriangleSelector*  selector=smgr->createTriangleSelector(map->getMesh(), map);
    core::vector3df     outCollisionPoint;
    core::triangle3df   outTriangle;
    ISceneNode*         outNode=nullptr;

    ISceneCollisionManager* colmgr = smgr->getSceneCollisionManager();
    line3d<float> raytrace = colmgr->getRayFromScreenCoordinates(device->getCursorControl()->getPosition(), camera);
    colmgr->getCollisionPoint(	raytrace,
                                selector,
                                outCollisionPoint,
                                outTriangle,
                                outNode
                                );

    selector->drop();
    return outCollisionPoint.Y;
}


MeshNode* RenderIrrlicht::createMesh(char* s)
{
    IMesh* mesh = smgr->getMesh(s); //Gets a mesh
    IMeshSceneNode* node = nullptr;
    if (mesh)
    {
        node = smgr->addMeshSceneNode(mesh);//Adds the mesh to the node
        node->setMaterialFlag(EMF_LIGHTING, true);
        node->setAutomaticCulling( EAC_BOX ); 
        //node->setMaterialFlag(EMF_WIREFRAME, true);
        //node->setDebugDataVisible(EDS_BBOX);
    }

    return new MeshNode(node);
}

CameraNode* RenderIrrlicht::createCamera()
{
    ICameraSceneNode* node = smgr->addCameraSceneNode(0, vector3df(0,0,0), vector3df(0,0,0));
    camera = node;
    node->setAutomaticCulling(EAC_OCC_QUERY);
    return new CameraNode(node);
}

ITexture* RenderIrrlicht::getTexture(char* s)
{
    return driver->getTexture(s);
}