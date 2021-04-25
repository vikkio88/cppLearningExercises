#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>
#include <cmath>

#include "helpers.hpp"

void processInput(GLFWwindow *window);

int main()
{
    glfwInit();

    // this was breaking the world
    //glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    // glxinfo | grep "OpenGL version"
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    const uint32_t WIDTH = 800, HEIGHT = 600;
    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGl - Tutorial", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return EXIT_FAILURE;
    }
    glViewport(0, 0, WIDTH, HEIGHT);

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(&messageCallback, 0);

    auto sources = loadShaderSources("triangle");

    // defining the vertex shader code
    unsigned int vertexShader = createShader(ShaderType::Vertex, sources.vertex);
    // defining the fragment shader code
    unsigned int fragmentShader = createShader(ShaderType::Fragment, sources.fragment);

    //creating program
    unsigned int shaderProgram = createProgram(vertexShader, fragmentShader);

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

        // V2
        // pos
        0.5f,
        -0.5f,
        0.0f,
        // colour GREEN
        0.f,
        1.f,
        0.f,

        // V3
        // pos
        0.0f,
        0.5f,
        0.0f,
        // colour BLUE
        0.f,
        0.f,
        1.f,

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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GL_FLOAT), nullptr);
    glEnableVertexAttribArray(0);
    // colours
    // stride as pos, but offset (initial offset is 3 * float, since is after the pos)
    // and for some reason needs to be a void*
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GL_FLOAT), (GLvoid *)(sizeof(GLfloat) * 3));
    glEnableVertexAttribArray(1);

    // index buffer object creation using indices
    unsigned int indexBufferObject;
    glGenBuffers(1, &indexBufferObject);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //LOOP
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(.1f, .1f, .1f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        //using the program
        glUseProgram(shaderProgram);
        glBindVertexArray(vertexArrayObject);
        // draw points 0-3 from the currently bound VAO with current in-use shader
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // clearing up window
    glfwDestroyWindow(window);
    glfwTerminate();

    return EXIT_SUCCESS;
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}