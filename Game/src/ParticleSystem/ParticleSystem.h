#include "Katana.h"

class ParticleSystem
{
    private:
        float x, y , z;
        float velocity, theta, phi, startTime;
        GLuint nParticles = 1000;
        GLfloat * data; 

    public:
        ParticleSystem(){}
        ~ParticleSystem(){}

        void init();
        float randFloat();
        void animate();
};