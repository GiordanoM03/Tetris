#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <ncurses.h>
#include <cstdlib>

const int GRID_HEIGHT = 20;
const int GRID_WIDTH = 10;
const int NUM_SHAPES = 9;

extern bool shapes[NUM_SHAPES][4][4];

class Shape
{
public:
    bool shape[4][4];
    int shapeIndex;
    short x, y;

    Shape();
    void setXY(short x, short y);
    void ResetXY();
    void setRandomShape();
    void draw() const;
    bool checkCollision(int grid[GRID_HEIGHT][GRID_WIDTH], int newX, int newY) const;
    void moveLeft(int grid[GRID_HEIGHT][GRID_WIDTH]);
    void moveRight(int grid[GRID_HEIGHT][GRID_WIDTH]);
    void moveDown();
    void rotateClockwise();
    void rotateCounterClockwise();
};

#endif 
