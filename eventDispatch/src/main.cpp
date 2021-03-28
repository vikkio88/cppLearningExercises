#include "eventDispatcher/EventDispatcher.hpp"

#include <iostream>
#include <functional>
#include <chrono>
#include <vector>
#include <future>
#include <random>

using namespace std::chrono_literals;

static ed::EventDispatcher dispatcher;

void generateEvent(int threadNum)
{
    std::random_device rd;
    std::default_random_engine rng(rd());
    int wait = (rng() % 10) + 1;
    const std::string event = (rng() % 100) > 50 ? "maurizio" : "mario";
    std::cout << "t: " << threadNum << " , waiting for " << wait << " secs" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(wait));
    std::cout << "t: " << threadNum << " generating " << event << " event" << std::endl;
    dispatcher.dispatch(ed::Event(event));
}

int main()
{
    const int THREADS = 3;
    std::vector<std::future<void>> futures;

    for (size_t i = 0; i < THREADS; i++)
    {
        futures.push_back(std::async(std::launch::async, generateEvent, i));
    }
    auto lambda = []() { std::cout << "yo Maurizio\n"; };
    auto lambda1 = []() { std::cout << "yo Mario\n"; };
    dispatcher.addListener("maurizio", lambda);
    dispatcher.addListener("mario", lambda);

    return EXIT_SUCCESS;
}