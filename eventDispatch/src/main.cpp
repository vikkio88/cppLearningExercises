#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <future>
#include <functional>
#include <chrono>
#include <random>
#include <map>

using namespace std::chrono_literals;

class Event
{
private:
    std::string m_Name;

public:
    Event(std::string name) : m_Name(name) {}
    std::string getName() const
    {
        return m_Name;
    }
};
static std::mutex subMutex;

class EventDispatcher
{
private:
    std::map<std::string, std::vector<std::function<void()>>> m_Listeners;
    std::map<std::string, int> m_CallCounts;

public:
    void dispatch(Event event)
    {
        auto subs = m_Listeners.find(event.getName());
        if (subs != m_Listeners.end())
        {
            m_CallCounts[event.getName()] += 1;
            std::cout << event.getName() << " been called " << m_CallCounts[event.getName()] << "times\n";
            for (auto &func : subs->second)
                func();
        }
    }

    void addListener(const char *eventName, const std::function<void()> &callback)
    {
        std::lock_guard<std::mutex> lock(subMutex);
        m_CallCounts[eventName] = 0;
        m_Listeners[eventName].push_back(callback);
    }

    ~EventDispatcher()
    {
        std::cout << "Destroying" << std::endl;
    }
};

static EventDispatcher dispatcher;

void generateEvent(int threadNum)
{
    std::random_device rd;
    std::default_random_engine rng(rd());
    int wait = (rng() % 10) + 1;
    const std::string event = (rng() % 100) > 50 ? "maurizio" : "mario";
    std::cout << "t: " << threadNum << " , waiting for " << wait << " secs" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(wait));
    std::cout << "t: " << threadNum << " generating " << event << " event" << std::endl;
    dispatcher.dispatch(Event(event));
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