#pragma once

#include "yoku/Game.hpp"
#include <string>

class TestGame : public yoku::Game
{
public:
    TestGame(const std::string &name);
};
