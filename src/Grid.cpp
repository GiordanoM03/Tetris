#include "Grid.hpp"

Grid::Grid(){
    for (int y = 0; y < GRID_HEIGHT; ++y)
        for (int x = 0; x < GRID_WIDTH; ++x)
            grid[y][x] = 0;
}

void Grid::draw(/*WINDOW* win*/) const{
    attrset(COLOR_PAIR(10));
    for (int y = 0; y < GRID_HEIGHT; ++y)
        for (int x = 0; x < GRID_WIDTH; ++x)
            if (grid[y][x] == 0)
                mvwprintw(stdscr, y, x * 2, " * ");
            else
                mvwprintw(stdscr, y, x * 2, "[]");
}

void Grid::placeShape(const Shape &shape){
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (shape.shape[i][j])
                grid[shape.y + i][shape.x + j] = 1;
}

void Grid::checkLines(int &Score){
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
}