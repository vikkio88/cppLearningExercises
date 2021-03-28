#include "Event.hpp"

#include <string>

namespace ed
{

    Event::Event(std::string name) : m_Name(name) {}
    std::string Event::getName() const
    {
        return m_Name;
    }
}
