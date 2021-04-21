#include "helpers.hpp"

#include <array>
#include <iostream>
#include <fstream>
#include <sstream>

void messageCallback(GLenum source, GLenum type, unsigned int x, unsigned int y, int z, const char *a, const void *b)
{
    std::cout << "ERROR: " << source << " " << type << " " << x << " " << y << " " << z << " " << a << " " << b << " " << std::endl;
}

void framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

ShaderSource loadShaderSources(const std::string &name)
{
    std::array<std::string, 2> sources;
    std::fstream f;
    std::stringstream ss;

    auto filename = "assets/shaders/" + name + ".vert";
    std::ifstream file(filename);
    if (!file)
    {
        std::cout << "Error reading: " + filename << std::endl;
    }
    ss << file.rdbuf();
    sources[0] = ss.str();

    file.close();
    ss.str("");

    filename = "assets/shaders/" + name + ".frag";
    file.open(filename);
    if (!file)
    {
        std::cout << "Error reading: " + filename << std::endl;
    }
    ss << file.rdbuf();
    sources[1] = ss.str();
    file.close();

    return {sources[0], sources[1]};
}

unsigned int createShader(ShaderType type, const std::string &source)
{
    auto shaderType = shaderTypesMap[type];
    const char *sourceCode = source.c_str();
    unsigned int shaderPtr = glCreateShader(shaderType);
    glShaderSource(shaderPtr, 1, &sourceCode, nullptr);
    glCompileShader(shaderPtr);

    int success;
    char infoLog[512];
    glGetShaderiv(shaderPtr, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        auto typeName = (shaderType == GL_VERTEX_SHADER) ? "VERTEX" : "FRAGMENT";
        std::cout << "[ERROR] Failed Compilation [" << typeName << "]\n"
                  << infoLog << std::endl;
        //maybe exception here
        return 0;
    }

    return shaderPtr;
}

unsigned int createProgram(unsigned int vertexShader, unsigned int fragmentShader)
{
    unsigned int shaderProgram = glCreateProgram();
    //linking our shaders
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                  << infoLog << std::endl;
        //maybe exception here
        return 0;
    }

    // removing shaders after linking
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}