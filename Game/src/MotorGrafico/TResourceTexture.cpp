#include "TResource.h"
#include "TResourceTexture.h"

bool TResourceTexture::loadResource()
{
    //Image residing in normal ram allows it to be manipulated freely.
    sf::Image* texture = new sf::Image();

    if(texture->loadFromFile(name))
    {
        //generate an OpenGL texture object.
        glGenTextures(1, &textureID);

        //binding texture in a 2d
        glBindTexture(GL_TEXTURE_2D, textureID);

        // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,img_data.GetWidth(), img_data.GetHeight(),0,GL_RGBA, GL_UNSIGNED_BYTE, img_data.GetPixelsPtr());
        glTexImage2D(GL_TEXTURE_2D, 0,GL_RGBA, texture->getSize().x, texture->getSize().y, 0, GL_BGRA, GL_UNSIGNED_BYTE, texture->getPixelsPtr());

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        delete texture;
        return true;
    }
    return false;
}