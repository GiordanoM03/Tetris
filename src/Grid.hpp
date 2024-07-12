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