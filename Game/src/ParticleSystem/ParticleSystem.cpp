#include "ParticleSystem.h"

const float PI = 3.1416;
const float TWOPI = 3.1416 * 2;


void ParticleSystem::init()
{
    glm::vec3 v(0.0f);
    data = new GLfloat[nParticles * 3];
    for(GLuint i = 0; i<nParticles; i++)
    {
        //Pick the direction of the velocity
        theta = glm::mix(0.0f, (float)PI /6.0f, randFloat());
        phi = glm::mix(0.f, (float)TWOPI, randFloat());

        v.x = sinf(theta) * cosf(phi);
        v.y = cosf(theta);
        v.z = sinf(theta) * sinf(phi);

        //Scale to set the magnitude of the velocity (speed)
        velocity = glm::mix(1.25f, 1.5f, randFloat());
        v = v * velocity;

        data[3*i]       = v.x;
        data[3*i + 1]   = v.y;
        data[3*i + 2]   = v.z;
    }
}


float ParticleSystem::randFloat()
{
    return ((float) rand()) / (float) 1.f;
}

void  ParticleSystem::animate()
{
    /*
    To pick vectors from within our cone, we utilize spherical coordinates. The value of theta
    determines the angle between the center of the cone and the outer edge. The value of phi

    defines he ossible direcions arond he y-axis for a given value of theta. For more on
    spherical coordinates, grab your favorite math book.

    Once a direction is chosen, the vector is scaled to have a magnitude between 1.25 and 1.5.
    The magnitude of the velocity vector is the overall speed of the particle. We can tweak this
    range to get a wider variety of speeds or faster/slower particles.

    The last three lines in the loop assign the vector to the appropriate location in the array data.
    After the loop, we copy the data into the buffer referred to by initVel. Set up this buffer to
    provide data for vertex attribute zero.
    
    In the second buffer, we'll store the start time for each particle. This will provide only a single
    floa per verex (paricle). For his example, we'll just create each perticle created 0.00075 seconds
    afet the previous one:
    */

    float * data = new GLfloat[nParticles];
    float time = 0.f, rate = 0.00075f;

    for(unsigned int i = 0; i<nParticles; i++)
    {
        data[i] = time;
        time += rate;
    }

    glBindBuffer(GL_ARRAY_BUFFER, startTime);
    glBufferSubData(GL_ARRAY_BUFFER, 0, nParticles * sizeof(float), data);


    /*
    This code simply crates an array of floats that start at zero and increment by rate. The array
    is then copied into the buffer referred to by startTime. Set this buffer to be the input for
    vertex attribute one.

        SET THE FOLLOWING UNIFORM PARTICLES:
            - ParticleText: the particle's textuire
            - Time: the amount of thiem that has elapsed since the animation began
            - Gravity: the vector representing one half of the aceleration in the preceding equation
            - ParticleLifeTime: How long a particle survives after is created
    */

   //Make sure that the depth test is off, and enable aplha blending using the followig statements
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //You will also want to choose a reasonable size for each point sprite. for example
    //the following line sets it to 10 pixels:
    glPointSize(10.f);

}



/*
//Use the following code for the vertex shader:

#version 400
// Initial velocity and start time
layout (location = 0) in vec3 VertexInitVel;
layout (location = 1) in float StartTime;
out float Transp;

 // Transparency of the particle
uniform float Time; // Animation time
uniform vec3 Gravity = vec3(0.0,-0.05,0.0); // world coords
uniform float ParticleLifetime; // Max particle lifetime
uniform mat4 MVP;

void main()
{
    // Assume the initial position is (0,0,0).
    vec3 pos = vec3(0.0);
    Transp = 0.0;

    // Particle doesn't exist until the start time
    if( Time >StartTime ) 
    {
        float t = Time - StartTime;
        if( t <ParticleLifetime ) 
        {
            pos = VertexInitVel * t + Gravity * t * t;
            Transp = 1.0 - t / ParticleLifetime;
        }
    }
gl_Position = MVP * vec4(pos, 1.0);
}
*/




/*
//Use the following code for the fragment shader:

#version 400
in float Transp;
uniform sampler2D ParticleTex;
layout ( location = 0 ) out vec4 FragColor;

void main()
{
    FragColor = texture(ParticleTex, gl_PointCoord);
    FragColor.a *= Transp;
}

*/