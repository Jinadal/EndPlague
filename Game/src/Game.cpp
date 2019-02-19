#include <stdlib.h>
#include <stdio.h>
#include "Game.h"
#include "../Facade/Facade.h"


#include "TTransform.h"
#include "TCamera.h"
#include "TLight.h"
#include "TMesh.h"
#include "TNode.h"
#include "TResourceTexture.h"
#include "TResourceManager.h"
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>
#include <glm/ext.hpp>
#define GLM_ENABLE_EXPERIMENTAL 
#include <glm/gtx/string_cast.hpp>


#include <iostream>

Game* Game::only_instance = nullptr;

void windowTest();
void treeTest();
void transformationTest();
void resourceTest();

void Game::run()
{
  windowTest();
    //treeTest();
    //transformationTest();
    //resourceTest();
}
void windowTest()
{
  Facade* facade = new Facade();
  facade->initWindow();

   
}

void resourceTest()
{
    TResourceManager* manager = new TResourceManager();
    manager->getResourceTexture("blue.bmp");
    manager->getResourceTexture("blue.bmp");
    manager->getResourceTexture("blue.jpg"); 
    delete manager;
    //texture->setName("./asd.jpg");
}

void transformationTest()
{
    TNode* Scene     = new TNode();

    TNode* LightRot  = new TNode(Scene);
    TNode* CamRot    = new TNode(LightRot);

    Scene->setId(0);
    LightRot->setId(1);
    CamRot->setId(2);

    Scene->addChild(LightRot);
    //Scene->addChild(CamRot);
    LightRot->addChild(CamRot);

    TNode* LightTras  = new TNode(LightRot);
    TNode* CamTras    = new TNode(LightTras);

    LightTras->setId(4);
    CamTras->setId(5);

    LightRot->addChild(LightTras);
    LightTras->addChild(CamTras);

    TTransform* TrasRotLight = new TTransform();
    TTransform* TrasRotCam = new TTransform();

    float aaa[16];
    glm::mat4 bbb = glm::make_mat4(aaa);


    TrasRotLight->setMatrix(bbb);
    TrasRotCam->setMatrix(bbb);

    TrasRotLight->identity();
    TrasRotCam->identity();

    TrasRotLight->modelMatrix() = glm::mat4(1.f);

    LightRot->setEntity((TEntity*)TrasRotLight);
    CamRot->setEntity((TEntity*)TrasRotCam);

    TTransform* TrasTrasLight = new TTransform();
    TTransform* TrasTrasCam = new TTransform();

    LightTras->setEntity((TEntity*)TrasTrasLight);
    CamTras->setEntity((TEntity*)TrasTrasCam);

    TrasTrasLight->setMatrix(bbb);
    TrasTrasCam->setMatrix(bbb);

    TrasTrasLight->identity();
    TrasTrasCam->identity();

    //TrasRotLight->scale(2.0,1.0,4.f);
    
    TrasRotLight->translate(1.0,0.0,0.0);
    TrasTrasLight->translate(0.f,1.f,0.f);

    TrasRotLight->inverse();
    //TrasRotLight->transpose();
    //TrasRotLight->translate(0.f,1.f,0.f);

    //TrasTrasLight->translate(1.f,0.f,0.f);

    //TrasRotLight->rotate(0.f,0.f,0.1,45.f);

    
    Scene->draw();
    delete TrasRotLight,
    delete TrasRotCam;
    delete TrasTrasLight;
    delete TrasTrasCam;
    //std::cout << "Im matrix from TrasRotLight : " <<glm::to_string(TrasRotLight->getMatrix()) << std::endl;
    //std::cout << "Im matrix from TrasRotCam : " << glm::to_string(TrasRotCam->getMatrix()) << std::endl;
    //std::cout << "Im matrix from TrasTrasLight : " << glm::to_string(TrasTrasLight->getMatrix()) << std::endl;
    //std::cout << "Im matrix from TrasTrasCam : " << glm::to_string(TrasTrasCam->getMatrix()) << std::endl;
    delete Scene;
}

void treeTest()
{
    TNode* Scene     = new TNode();

    TNode* LightRot  = new TNode(Scene);
    TNode* CamRot    = new TNode(Scene);
    TNode* CarRot    = new TNode(Scene);

    Scene->setId(0);
    LightRot->setId(1);
    CamRot->setId(2);
    CarRot->setId(3);

    Scene->addChild(LightRot);
    Scene->addChild(CamRot);
    Scene->addChild(CarRot);

    TNode* LightTras  = new TNode(LightRot);
    TNode* CamTras    = new TNode(CamRot);
    TNode* CarTras    = new TNode(CarRot);
    
    LightTras->setId(4);
    CamTras->setId(5);
    CarTras->setId(6);

    LightRot->addChild(LightTras);
    CamRot->addChild(CamTras);
    CarRot->addChild(CarTras);

    TTransform* TrasRotLight = new TTransform();
    TTransform* TrasRotCam = new TTransform();
    TTransform* TrasRotCar = new TTransform();

    LightRot->setEntity((TEntity*)TrasRotLight);
    CamRot->setEntity((TEntity*)TrasRotCam);
    CarRot->setEntity((TEntity*)TrasRotCar);

    TLight* EntLight = new TLight();
    TCamera* EntCam = new TCamera();
    TMesh* EntMesh = new TMesh();

    TNode* NLight  = new TNode(LightTras);
    TNode* NCam    = new TNode(CamTras);
    TNode* NCar    = new TNode(CarTras);

    NLight->setId(7);
    NCam->setId(8);
    NCar->setId(9);

    LightTras->addChild(NLight);
    CamTras->addChild(NCam);
    CarTras->addChild(NCar);

    NLight->setEntity(EntLight);
    NCam->setEntity(EntCam);
    NCar->setEntity(EntMesh);
  
    LightTras->popChild(NLight);
    NLight->setFather(NCar);
    NCar->addChild(NLight);

    Scene->draw();

  //Scene->killBranch();
  //delete LightRot;
  //delete CamRot;
  //delete CarRot;
  //delete LightTras;
  //delete CamTras;
  //delete CarTras;
    delete TrasRotLight,
    delete TrasRotCam;
    delete TrasRotCar;
    delete EntLight;
    delete EntCam;
    delete EntMesh;
  //delete NLight;
  //delete NCam;
  //delete NCar;
    delete Scene;
}