#pragma once

class Application
{
private:
    void initVulkan();
    void mainLoop();

    void cleanup();

public:
    Application();
    void run();
};