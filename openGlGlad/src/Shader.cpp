#include "Shader.hpp"

#include <array>
#include <iostream>
#include <fstream>
#include <sstream>

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
        glGetShaderInfoLog(shaderPtr, 512, nullptr, infoLog);
        auto typeName = (shaderType == GL_VERTEX_SHADER) ? "VERTEX" : "FRAGMENT";
        std::cout << "[ERROR] Failed Compilation [" << typeName << "]\n"
                  << infoLog << std::endl;
        //maybe exception here
        return 0;
    }

    return shaderPtr;
}

Shader::Shader(const std::string &name, const std::string &path) : m_name(name), m_path(path)
{
    loadSources();
    createShaders();
    createProgram();
}

void Shader::loadSources()
{
    std::array<std::string, 2> sources;
    std::fstream f;
    std::stringstream ss;

    auto filename = m_path + "/" + m_name + ".vert";
    std::ifstream file(filename);
    if (!file)
    {
        std::cout << "Error reading: " + filename << std::endl;
    }
    ss << file.rdbuf();
    sources[0] = ss.str();

    file.close();
    ss.str("");

    filename = m_path + "/" + m_name + ".frag";
    file.open(filename);
    if (!file)
    {
        std::cout << "Error reading: " + filename << std::endl;
    }
    ss << file.rdbuf();
    sources[1] = ss.str();
    file.close();

    m_sources = {sources[0], sources[1]};
}

void Shader::createShaders()
{
    m_shaders[0] = createShader(ShaderType::Vertex, m_sources.vertex);
    m_shaders[1] = createShader(ShaderType::Fragment, m_sources.fragment);
}

void Shader::createProgram()
{
    m_program = glCreateProgram();
    glAttachShader(m_program, m_shaders[0]);
    glAttachShader(m_program, m_shaders[1]);
    glLinkProgram(m_program);
    int success;
    glGetProgramiv(m_program, GL_LINK_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetProgramInfoLog(m_program, 512, NULL, infoLog);
        std::cout << "[ERROR] Failed Linking shaders to program\n"
                  << infoLog << std::endl;
        //throw exception here
    }

    cleanup();
}

void Shader::cleanup()
{
    // removing shaders after linking
    glDeleteShader(m_shaders[0]);
    glDeleteShader(m_shaders[1]);
}

void Shader::use()
{
    glUseProgram(m_program);
}
