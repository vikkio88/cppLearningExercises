#include <iostream>
#include <vector>
#include <future>
#include <thread>

static std::mutex vMutex;

void yo(std::vector<int> *v, int i)
{
    std::lock_guard<std::mutex> lock(vMutex);
    std::cout << "yo: " << i << "\n";
    v->push_back(i);
}

int main()
{
    std::vector<int> v;
    std::vector<std::future<void>> futures;
    std::cout << "Yo!" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        futures.push_back(std::async(std::launch::async, yo, &v, i));
    }

    return EXIT_SUCCESS;
}