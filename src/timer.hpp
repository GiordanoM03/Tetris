#ifndef TIMER_HPP
#define TIMER_HPP

#include "grid.hpp"
#include "tetromino.hpp"
#include <thread>
#include <chrono>

class Timer {
public:
    Timer(Grid& grid, Tetris::Tetromino& tetromino);
    void start();

private:
    Grid& grid;
    Tetris::Tetromino& tetromino;
    int startRow;
    int startCol;
    bool gameRunning;

    void gameLoop();
    
};

#endif 





