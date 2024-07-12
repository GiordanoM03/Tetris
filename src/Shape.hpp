#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <cstdlib>
#include <ncurses.h>
using namespace std;

#define GRID_HEIGHT 20
#define GRID_WIDTH 10
#define NUM_SHAPES 7

bool shapes[NUM_SHAPES][4][4] = {
    {{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, //cuve
    {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}}, //long
    {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, //t
    {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}}, //L
    {{0, 1, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}}, //reverese L
    {{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, //z
    {{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}};//s

class Shape {
public:
    bool shape[4][4];
    int shapeIndex;
    short x, y;

    Shape() : shapeIndex(0), x((GRID_WIDTH / 2) + 1), y(0)
    {
        setRandomShape();
    }
    void setXY(short x, short y);
    void ResetXY();
    void setRandomShape();

    void draw(/*WINDOW* win*/) const;

    bool checkCollision(int grid[GRID_HEIGHT][GRID_WIDTH], int newX, int newY) const;

    void moveLeft(int grid[GRID_HEIGHT][GRID_WIDTH]);

    void moveRight(int grid[GRID_HEIGHT][GRID_WIDTH]);

    void moveDown();
    void rotateClockwise();
    void rotateCounterClockwise();
};

#endif //SHAPE_HPP