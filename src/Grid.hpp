<<<<<<< HEAD
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

=======
#ifndef GRID_HPP
#define GRID_HPP

#include "Shape.cpp"

class Grid {
public:
    int grid[GRID_HEIGHT][GRID_WIDTH];

    Grid();

    void draw(/*WINDOW* win*/) const;

    void placeShape(const Shape &shape);
    void checkLines(int &Score);
};

#endif //GRID_HPP
>>>>>>> cddcac4384ead00e599165e15a19c436c24a775d
