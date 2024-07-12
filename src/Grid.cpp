#include "Grid.hpp"

<<<<<<< HEAD
Grid::Grid()
{
=======
Grid::Grid(){
>>>>>>> cddcac4384ead00e599165e15a19c436c24a775d
    for (int y = 0; y < GRID_HEIGHT; ++y)
        for (int x = 0; x < GRID_WIDTH; ++x)
            grid[y][x] = 0;
}

<<<<<<< HEAD
void Grid::draw() const
{
=======
void Grid::draw(/*WINDOW* win*/) const{
>>>>>>> cddcac4384ead00e599165e15a19c436c24a775d
    attrset(COLOR_PAIR(10));
    for (int y = 0; y < GRID_HEIGHT; ++y)
        for (int x = 0; x < GRID_WIDTH; ++x)
            if (grid[y][x] == 0)
<<<<<<< HEAD
                mvprintw(y, x * 2, " * ");
            else
                mvprintw(y, x * 2, "[]");
}

void Grid::placeShape(const Shape &shape)
{
=======
                mvwprintw(stdscr, y, x * 2, " * ");
            else
                mvwprintw(stdscr, y, x * 2, "[]");
}

void Grid::placeShape(const Shape &shape){
>>>>>>> cddcac4384ead00e599165e15a19c436c24a775d
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (shape.shape[i][j])
                grid[shape.y + i][shape.x + j] = 1;
}

<<<<<<< HEAD
void Grid::checkLines(int &Score)
{
=======
void Grid::checkLines(int &Score){
>>>>>>> cddcac4384ead00e599165e15a19c436c24a775d
    for (int y = GRID_HEIGHT - 1; y >= 0; --y)
    {
        bool lineComplete = true;
        for (int x = 0; x < GRID_WIDTH; ++x)
        {
            if (grid[y][x] == 0)
            {
                lineComplete = false;
                break;
            }
        }
        if (lineComplete)
        {
            Score += 100;
            for (int k = y; k > 0; --k)
                for (int x = 0; x < GRID_WIDTH; ++x)
                    grid[k][x] = grid[k - 1][x];
            for (int x = 0; x < GRID_WIDTH; ++x)
                grid[0][x] = 0;
        }
    }
<<<<<<< HEAD
}
=======
}
>>>>>>> cddcac4384ead00e599165e15a19c436c24a775d
