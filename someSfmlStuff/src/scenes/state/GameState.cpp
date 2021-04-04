#include "GameState.hpp"

GameState *GameState::instance = nullptr;

GameState::GameState(){
    lines = new Lines();
    shapes = new Shapes();
}
