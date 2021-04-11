#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Titlebar, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);
    window.setActive(true);

    sf::Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        // inside the main loop
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 1.f, 1.f);
        glVertex3f(-.9f, -.5f, 10.f);
        glVertex3f(0.0f, 0.5f, 0.5f);
        glVertex3f(1.f, -0.5f, 0.f);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(0.f, 0.f, 0.f);
        glVertex3f(0.f, 0.f, 20.f);

        glVertex3f(0.f, 0.f, 0.f);
        glVertex3f(0.f, 20.f, 0.f);

        glVertex3f(0.f, 0.f, 0.f);
        glVertex3f(20.f, 0.f, 0.f);
        glEnd();

        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }

    return EXIT_SUCCESS;
}