#include "Shape.hpp"

<<<<<<< HEAD
bool shapes[NUM_SHAPES][4][4] = {
    {{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
    {{1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}},
    {{0, 1, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}},
    {{1, 1, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {0, 0, 0, 0}},
    {{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}};

Shape::Shape() : shapeIndex(0), x((GRID_WIDTH / 2) + 1), y(0)
{
    setRandomShape();
}

void Shape::setXY(short x, short y)
{
=======
void Shape::setXY(short x, short y){
>>>>>>> cddcac4384ead00e599165e15a19c436c24a775d
    this->x = x;
    this->y = y;
}

<<<<<<< HEAD
void Shape::ResetXY()
{
=======
void Shape::ResetXY(){
>>>>>>> cddcac4384ead00e599165e15a19c436c24a775d
    this->x = (GRID_WIDTH / 2) + 1;
    this->y = 0;
}

<<<<<<< HEAD
void Shape::setRandomShape()
{
=======
void Shape::setRandomShape(){
>>>>>>> cddcac4384ead00e599165e15a19c436c24a775d
    shapeIndex = rand() % NUM_SHAPES;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            shape[i][j] = shapes[shapeIndex][i][j];
}

<<<<<<< HEAD
void Shape::draw() const
{
    attrset(COLOR_PAIR(shapeIndex));
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (shape[i][j])
                mvprintw(y + i, (x + j) * 2, "[]");
}

bool Shape::checkCollision(int grid[GRID_HEIGHT][GRID_WIDTH], int newX, int newY) const
{
=======
void Shape::draw(/*WINDOW* win*/) const{
    attrset(COLOR_PAIR(shapeIndex));
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (shape[i][j]) {
                mvwprintw(stdscr, y + i, (x + j) * 2, "[]");
            }
}

bool Shape::checkCollision(int grid[GRID_HEIGHT][GRID_WIDTH], int newX, int newY) const{
>>>>>>> cddcac4384ead00e599165e15a19c436c24a775d
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (shape[i][j] && (newX + j < 0 || newX + j >= GRID_WIDTH || newY + i >= GRID_HEIGHT || grid[newY + i][newX + j]))
                return true;
    return false;
}

<<<<<<< HEAD
void Shape::moveLeft(int grid[GRID_HEIGHT][GRID_WIDTH])
{
=======
void Shape::moveLeft(int grid[GRID_HEIGHT][GRID_WIDTH]){
>>>>>>> cddcac4384ead00e599165e15a19c436c24a775d
    if (!checkCollision(grid, x - 1, y))
        x--;
}

<<<<<<< HEAD
void Shape::moveRight(int grid[GRID_HEIGHT][GRID_WIDTH])
{
=======
void Shape::moveRight(int grid[GRID_HEIGHT][GRID_WIDTH]){
>>>>>>> cddcac4384ead00e599165e15a19c436c24a775d
    if (!checkCollision(grid, x + 1, y))
        x++;
}

<<<<<<< HEAD
void Shape::moveDown()
{
    y++;
}

void Shape::rotateClockwise()
{
=======
void Shape::moveDown(){
    y++;
}

void Shape::rotateClockwise(){
>>>>>>> cddcac4384ead00e599165e15a19c436c24a775d
    bool temp[4][4];

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            temp[j][4 - i - 1] = shape[i][j];

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            shape[i][j] = temp[i][j];
}

<<<<<<< HEAD
void Shape::rotateCounterClockwise()
{
=======
void Shape::rotateCounterClockwise(){
>>>>>>> cddcac4384ead00e599165e15a19c436c24a775d
    bool temp[4][4];

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            temp[4 - j - 1][i] = shape[i][j];

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            shape[i][j] = temp[i][j];
<<<<<<< HEAD
}
=======
}
>>>>>>> cddcac4384ead00e599165e15a19c436c24a775d
