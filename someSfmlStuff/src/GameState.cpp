#include "GameState.hpp"

GameState *GameState::instance = 0;

GameState::GameState(){
    lines = new Lines();
    shapes = new Shapes();
}
