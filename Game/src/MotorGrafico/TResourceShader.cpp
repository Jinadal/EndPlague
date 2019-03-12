#include "TResourceShader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


//Method that reads a shader and compiles it taken from the Internet
bool TResourceShader::loadResource()
{
    bool ret = false;
    const GLchar* source;

    id = glCreateShader(type);
    
    std::string line, allLines;
    std::ifstream theFile(name);
    if (theFile.is_open())
    {
        while (std::getline(theFile, line))
        {
            allLines = allLines + line + "\n";
        }

        source = allLines.c_str();
        std::cout << source;

        theFile.close();
    }
    else
    {
    std::cout << "Unable to open file.";
    }

    glShaderSource(id, 1, &source, nullptr);
    glCompileShader(id);

    return ret;
}