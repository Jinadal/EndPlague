#include "TSprite.h"
#include "SOIL.h"

TSprite::TSprite(char* path)
{
    texture = new Texture2D();
    
    texture->Internal_Format = GL_RGBA;
    texture->Image_Format = GL_RGBA;
    
    // Load image
    int width, height;
    unsigned char* image = SOIL_load_image(path, &width, &height, 0, texture->Image_Format == GL_RGBA ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
    // Now generate texture
    texture->Generate(width, height, image);
    // And finally free image data
    SOIL_free_image_data(image);
}