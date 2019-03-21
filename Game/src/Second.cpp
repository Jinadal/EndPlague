#include "Second.h"
#include "Katana.h"

Second* Second::only_instance = nullptr;



int Second::run()
{
	Katana* katana = new Katana();
	GLFWwindow* window = katana->initWindow();
    katana->initRoot();
	katana->initOpenGL();
    TNode* scene = katana->getSceneRoot();
	scene->setId(0);



   
	katana->createNodeCamera(scene,glm::vec3(10,0,5),glm::vec3(0,0,0),0.01f,1000.0f);
	katana->createNodeMesh(scene,glm::vec3(0,0,0),"Gema/Gema_02.OBJ");



	while(katana->openWindow(window))
	{
		katana->drawAll();
	} 

	katana->close();

	return 0;
}
