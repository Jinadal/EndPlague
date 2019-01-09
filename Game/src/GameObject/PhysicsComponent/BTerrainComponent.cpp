#include "BTerrainComponent.h"
#include <iostream>
#include <fstream>
#include <sstream>

 BTerrainComponent::BTerrainComponent(GameObject* owner, Manager* manager, char* mesh) : Component(owner, manager)
{
    std::ifstream inputFile;
    inputFile.open (mesh);
    std::string line;
    std::vector<btVector3> vertices;
    std::vector<btVector3> triangles;


    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);

        char c;
        iss >> c;

        if (line[0] == 'v' && line[1] == ' ') { //IS A VEREX
            btScalar x, y, z;
            iss >> x >> y >> z;
            btVector3 point(x, y, z);
            vertices.push_back(point);
        } else if (line[0] == 'f' && line[1] == ' ') { //IS A FACE
            std::string s1, s2, s3;
            iss >> s1 >> s2 >> s3;

            s1 = s1.substr(0, s1.find('/'));
            s2 = s2.substr(0, s2.find('/'));
            s3 = s3.substr(0, s3.find('/'));

            btScalar t1, t2, t3;
            t1 = std::stof(s1) - 1;
            t2 = std::stof(s2) - 1;
            t3 = std::stof(s3) - 1;
            btVector3 triangle(t1, t2, t3);

            triangles.push_back(triangle);
        }
    }

    //Then add the triangles to a btTriangleMesh
    btTriangleMesh *triangleMesh = new btTriangleMesh();
    for (const btVector3 &triangle : triangles)
        triangleMesh->addTriangle(vertices[triangle.x()], vertices[triangle.y()], vertices[triangle.z()]);

    //Finally add the triangle to a meshshape
    //btBvhTriangleMeshShape
    //btConvexTriangleMeshShape* shape = new btConvexTriangleMeshShape(triangleMesh);
    btBvhTriangleMeshShape* shape = new btBvhTriangleMeshShape(triangleMesh, true, true);
    rbody = PhysicBullet::getInstance()->createTerrain(btScalar(0.f), btVector3(gameObject->getX(), gameObject->getY(), gameObject->getZ()), shape);


    rbody->setUserPointer((void *)(gameObject));

}



void BTerrainComponent::update(){}
