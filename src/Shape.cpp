#include "Shape.hpp"

void Shape::setXY(short x, short y){
    this->x = x;
    this->y = y;
}

void Shape::ResetXY(){
    this->x = (GRID_WIDTH / 2) + 1;
    this->y = 0;
}

void Shape::setRandomShape(){
    shapeIndex = rand() % NUM_SHAPES;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            shape[i][j] = shapes[shapeIndex][i][j];
}

void Shape::draw(/*WINDOW* win*/) const{
    attrset(COLOR_PAIR(shapeIndex));
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (shape[i][j]) {
                mvwprintw(stdscr, y + i, (x + j) * 2, "[]");
            }
}

bool Shape::checkCollision(int grid[GRID_HEIGHT][GRID_WIDTH], int newX, int newY) const{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (shape[i][j] && (newX + j < 0 || newX + j >= GRID_WIDTH || newY + i >= GRID_HEIGHT || grid[newY + i][newX + j]))
                return true;
    return false;
}

void Shape::moveLeft(int grid[GRID_HEIGHT][GRID_WIDTH]){
    if (!checkCollision(grid, x - 1, y))
        x--;
}

void Shape::moveRight(int grid[GRID_HEIGHT][GRID_WIDTH]){
    if (!checkCollision(grid, x + 1, y))
        x++;
}

void Shape::moveDown(){
    y++;
}

void Shape::rotateClockwise(){
    bool temp[4][4];

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            temp[j][4 - i - 1] = shape[i][j];

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            shape[i][j] = temp[i][j];
}

void Shape::rotateCounterClockwise(){
    bool temp[4][4];

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            temp[4 - j - 1][i] = shape[i][j];

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            shape[i][j] = temp[i][j];
}