#pragma once

#include <string>

namespace ed
{
    class Event
    {
    private:
        std::string m_Name;

    public:
        Event(std::string name);
        std::string getName() const;
    };
}
