#version 330 core
in vec2 TexCoords;
out vec4 color;

uniform sampler2D image;
uniform vec3 spriteColor;
uniform bool transparency;
void main()
{    

    //if(transparency == true){

        //if(texture(image, TexCoords).w > 0.0){
            color = vec4(vec3(texture(image, TexCoords)), texture(image, TexCoords).w);
        //}else{
        //    discard;
        //}
    //}   
    //else
    //    color = vec4(spriteColor, 1.0) * texture(image, TexCoords);
    
}  