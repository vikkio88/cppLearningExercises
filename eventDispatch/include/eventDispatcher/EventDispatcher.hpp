#pragma once

#include "Event.hpp"

#include <string>
#include <map>
#include <vector>
#include <mutex>
#include <functional>

namespace ed
{

    class EventDispatcher
    {
    private:
        std::map<std::string, std::vector<std::function<void()>>> m_Listeners;
        std::map<std::string, int> m_CallCounts;

    public:
        static std::mutex subMutex;
        void dispatch(Event event);

        void addListener(const char *eventName, const std::function<void()> &callback);

        ~EventDispatcher();
    };
}