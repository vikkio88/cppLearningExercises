#include "EventDispatcher.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <future>
#include <functional>
#include <random>
#include <map>

namespace ed
{
    // Init static mutex
    std::mutex EventDispatcher::subMutex;

    void EventDispatcher::dispatch(Event event)
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

    void EventDispatcher::addListener(const char *eventName, const std::function<void()> &callback)
    {
        std::lock_guard<std::mutex> lock(subMutex);
        m_CallCounts[eventName] = 0;
        m_Listeners[eventName].push_back(callback);
    }

    EventDispatcher::~EventDispatcher()
    {
        std::cout << "Destroying" << std::endl;
    }
}