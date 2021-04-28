#pragma once

#include <glad/glad.h>
#include <string>
#include <array>

struct ShaderSource
{
    std::string vertex;
    std::string fragment;
};

enum ShaderType
{
    Vertex = 0,
    Fragment = 1
};

constexpr GLenum shaderTypesMap[] = {GL_VERTEX_SHADER, GL_FRAGMENT_SHADER};

class Shader
{
private:
    std::string m_name;
    std::string m_path;
    unsigned int m_program = 0;
    ShaderSource m_sources;
    std::array<unsigned int, 2> m_shaders = {0, 0};

    void loadSources();
    void createShaders();
    void createProgram();

    void cleanup();

public:
    Shader(const std::string &name, const std::string& path = "assets/shaders");

    void use();
};
