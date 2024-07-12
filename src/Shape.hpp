#ifndef SHAPE_HPP
#define SHAPE_HPP

<<<<<<< HEAD
#include <ncurses.h>
#include <cstdlib>

const int GRID_HEIGHT = 20;
const int GRID_WIDTH = 10;
const int NUM_SHAPES = 9;

extern bool shapes[NUM_SHAPES][4][4];

class Shape
{
=======
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
>>>>>>> cddcac4384ead00e599165e15a19c436c24a775d
public:
    bool shape[4][4];
    int shapeIndex;
    short x, y;

<<<<<<< HEAD
    Shape();
    void setXY(short x, short y);
    void ResetXY();
    void setRandomShape();
    void draw() const;
    bool checkCollision(int grid[GRID_HEIGHT][GRID_WIDTH], int newX, int newY) const;
    void moveLeft(int grid[GRID_HEIGHT][GRID_WIDTH]);
    void moveRight(int grid[GRID_HEIGHT][GRID_WIDTH]);
=======
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

>>>>>>> cddcac4384ead00e599165e15a19c436c24a775d
    void moveDown();
    void rotateClockwise();
    void rotateCounterClockwise();
};

<<<<<<< HEAD
#endif 
=======
#endif //SHAPE_HPP
>>>>>>> cddcac4384ead00e599165e15a19c436c24a775d
