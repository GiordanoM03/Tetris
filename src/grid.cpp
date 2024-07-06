#include "grid.hpp"
#include <iostream>

Grid::Grid() {
    clear(); 
}

void Grid::clear() {
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            grid[i][j] = 0;
        }
    }
}

void Grid::set(int row, int col, int value) {
    if (row >= 0 && row < righe && col >= 0 && col < colonne) {
        grid[row][col] = value;
    }
}

int Grid::get(int row, int col) const {
    if (row >= 0 && row < righe && col >= 0 && col < colonne) {
        return grid[row][col];
    }
    return -1;
}

bool Grid::isrowfull(int riga) const {
    for (int colonna = 0; colonna < colonne; ++colonna) {
        if (grid[riga][colonna] == 0) {
            return false; 
        }
    }
    return true; 
}

void Grid::removerow(int riga) {
    for (int r = riga; r > 0; --r) {
        for (int colonna = 0; colonna < colonne; ++colonna) {
            grid[r][colonna] = grid[r - 1][colonna]; 
        }
    }
    for (int colonna = 0; colonna < colonne; ++colonna) {
        grid[0][colonna] = 0; 
    }
}

void Grid::shiftdown(int riga) {
    for (int r = riga; r > 0; --r) {
        for (int colonna = 0; colonna < colonne; ++colonna) {
            grid[r][colonna] = grid[r - 1][colonna]; 
        }
    }
    for (int colonna = 0; colonna < colonne; ++colonna) {
        grid[0][colonna] = 0; 
    }
}

void Grid::print() const {
    for (int i = 0; i < colonne + 2; ++i) {
        std::cout << "#";
    }
    std::cout << std::endl;

    for (int riga = 0; riga < righe; ++riga) {
        std::cout << "#";
        for (int colonna = 0; colonna < colonne; ++colonna) {
            if (grid[riga][colonna] == 0) {
                std::cout << " "; 
            } else {
                std::cout << grid[riga][colonna];
            }
        }
        std::cout << "#" << std::endl; 
    }

    for (int i = 0; i < colonne + 2; ++i) {
        std::cout << "#";
    }
    std::cout << std::endl;
}

bool Grid::gameOver(int grid[21][10]) {
    for (int col = 0; col < 10; ++col) {
        if (grid[0][col] != 0) {
            return true;
        }
    }
    return false;
}

bool Grid::canPlaceTetromino(const int tetromino[4][4], int startRow, int startCol) const {
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            if (tetromino[row][col] != 0) {
                int newRow = startRow + row;
                int newCol = startCol + col;
                if (newRow < 0 || newRow >= righe || newCol < 0 || newCol >= colonne || grid[newRow][newCol] != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

void Grid::clearFullRows() {
    for (int row = 0; row < righe; ++row) {
        if (isrowfull(row)) {
            removerow(row);
        }
    }
}

bool Grid::isCellOccupied(int row, int col) const {
    if (row >= 0 && row < righe && col >= 0 && col < colonne) {
        return grid[row][col] != 0;
    }
    return true; 
}
