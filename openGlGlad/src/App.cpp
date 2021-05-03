#include "App.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#include <iostream>

void messageCallback(GLenum source, GLenum type, unsigned int x, unsigned int y, int z, const char *a, const void *b)
{
    std::cout << "ERROR: " << source << " " << type << " " << x << " " << y << " " << z << " " << a << " " << b << " " << std::endl;
}

App::App(const std::string &name, unsigned int width, unsigned int height)
    : m_window(name, width, height)
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;

        //throw exception
    }
    glViewport(0, 0, width, height);

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(&messageCallback, 0);

    init();
}

void App::init()
{
    //shaders
    float vertices[] = {
        // V1
        // pos
        -0.5f,
        -0.5f,
        0.0f,
        // colours RED
        1.0f,
        0.f,
        0.f,
        // text coord
        1.0f, 1.0f,

        // V2
        // pos
        0.5f,
        -0.5f,
        0.0f,
        // colour GREEN
        0.f,
        1.f,
        0.f,
        // text coord
        1.0f, 0.0f,

        // V3
        // pos
        0.0f,
        0.5f,
        0.0f,
        // colour BLUE
        0.f,
        0.f,
        1.f,
        // text coord
        0.0f, 0.0f,

        //v1t1 -> v3
        //v2t1 -> v2

        // V3T1
        // pos
        0.5f,
        0.5f,
        0.0f,
        // colour
        1.f,
        0.f,
        0.f,
        // text coord
        1.0f, 1.0f,

        //v1t2 -> v3
        //v2t2 -> v1
        //v3t2
        -0.5f,
        0.5f,
        0.0f,
        //col
        0.f,
        1.f,
        0.f,
        // text coord
        0.0f, 1.0f,
    };

    GLuint indices[] = {0, 1, 2, 2, 1, 3, 2, 0, 4};

    // data
    // X Y Z     R G B
    // <-- stride -->
    // distance between each attrib
    // offset -->
    // offset is 0 for pos, 3 * float for colour

    //creating vertex buffer object
    unsigned int vertexBufferObject;
    unsigned int vertexArrayObject = 0;

    glGenBuffers(1, &vertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);

    // position data
    // stride = 6 * GLFloat
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), nullptr);
    glEnableVertexAttribArray(0);
    // colours
    // stride as pos, but offset (initial offset is 3 * float, since is after the pos)
    // and for some reason needs to be a void*
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (GLvoid *)(sizeof(GLfloat) * 3));
    glEnableVertexAttribArray(1);
    // texture coords
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (GLvoid *)(sizeof(GLfloat) * 6));
    glEnableVertexAttribArray(2);

    // index buffer object creation using indices
    unsigned int indexBufferObject;
    glGenBuffers(1, &indexBufferObject);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // texture generation
    int width, height, nrChannels;
    unsigned char *data = stbi_load("assets/textures/wall.jpg", &width, &height, &nrChannels, 0);

    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);
    // this should be done after in draw ↓
    glBindTexture(GL_TEXTURE_2D, texture);

    //shader generation
    shader = std::make_unique<Shader>("triangle");
}

void App::run()
{
    while (!m_window.shouldClose())
    {
        m_window.processInput();
        clear();
        draw();

        m_window.swapBuffers();
        m_window.pollEvents();
    }

    m_window.~Window();
}

void App::clear()
{
    glClearColor(.1f, .1f, .1f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void App::draw()
{
    // using the shader program
    shader->use();
    // draw points 0-3 from the currently bound VAO with current in-use shader
    glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
}
