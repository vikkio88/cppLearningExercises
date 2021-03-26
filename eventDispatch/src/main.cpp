#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <chrono>
#include <random>

using namespace std::chrono_literals;

void printAndWait(int threadNum)
{
    std::random_device rd;
    std::default_random_engine rng(rd());
    int wait = (rng() % 10) + 1;
    std::cout << "t: " << threadNum << " , waiting for " << wait << " secs" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(wait));
    std::cout << "t: " << threadNum << " finished" << std::endl;
}

int main()
{
    const int THREADS = 3;
    std::vector<std::future<void>> futures;

    for (size_t i = 0; i < THREADS; i++)
    {
        futures.push_back(std::async(std::launch::async, printAndWait, i));
    }

    return EXIT_SUCCESS;
}