#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    // OpenGl Version => glxinfo | grep "OpenGL version"
    // 4.6 on my laptop
    settings.majorVersion = 4;
    settings.minorVersion = 6;
    settings.attributeFlags = sf::ContextSettings::Core;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "GlewTest", sf::Style::Titlebar, settings);
    glewExperimental = GL_TRUE;

    window.setActive(true);

    if (glewInit() != GLEW_OK)
    {
        std::cout << "Problems initialising GLEW/OPENGL\n";
        return EXIT_FAILURE;
    }

    glViewport(0, 0, WIDTH, HEIGHT);
    glMatrixMode(GL_PROJECTION);

    while (window.isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

        glClearColor(.3f, .2f, .5f, .9f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3f(0.0f, 0.0f, 1.0f);

        glBegin(GL_LINE_LOOP);
        glVertex3f(-1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, -1.0f, 0.0f);
        glVertex3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glEnd();
        window.display();
    }

    std::cout << "\n\nBye, have a good time\n";
    return EXIT_SUCCESS;
}