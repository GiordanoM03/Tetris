#include "timer.hpp"
#include <iostream>

Timer::Timer(Grid& grid, Tetris::Tetromino& tetromino)
    : grid(grid), tetromino(tetromino), startRow(0), startCol(grid.getColCount() / 2 - 2), gameRunning(true) {}

void Timer::start() {
    std::thread(&Timer::gameLoop, this).detach();
}

void Timer::gameLoop() {
    while (gameRunning) {
        if (grid.canPlaceTetromino(tetromino.getShape(), startRow + 1, startCol)) {
            startRow++;
        } else {
            grid.placeTetromino(tetromino, startRow, startCol);
            grid.clearFullRows();
            if (grid.gameOver()) {
                gameRunning = false;
                std::cout << "Game Over!" << std::endl;
                break;
            }
            tetromino = Tetris::Tetromino::getRandomTetromino();
            startRow = 0;
            startCol = grid.getColCount() / 2 - 2;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

