#ifndef GAME_HPP
#define GAME_HPP

#include "Grid.hpp"
#include "Shape.hpp"
#include <string>

class Game
{
private:
    Grid grid;
    Shape shape;
    Shape nextShape;
    int Score;

public:
    Game();
    void init();
    void end();
    void draw();
    void update();
    void handleInput();
    void run();
};

#endif 
