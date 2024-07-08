#include "grid.hpp"
#include <iostream>

Grid::Grid(int rows, int cols)
    : righe(rows), colonne(cols) {
    clear();
}

Grid::Grid(const Grid& other) {
    righe = other.righe;
    colonne = other.colonne;
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            grid[i][j] = other.grid[i][j];
        }
    }
}

Grid& Grid::operator=(const Grid& other) {
    if (this != &other) {
        righe = other.righe;
        colonne = other.colonne;
        for (int i = 0; i < righe; ++i) {
            for (int j = 0; j < colonne; ++j) {
                grid[i][j] = other.grid[i][j];
            }
        }
    }
    return *this;
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

bool Grid::isRowFull(int row) const {
    for (int col = 0; col < colonne; ++col) {
        if (grid[row][col] == 0) {
            return false;
        }
    }
    return true;
}

void Grid::removeRow(int row) {
    for (int r = row; r > 0; --r) {
        for (int col = 0; col < colonne; ++col) {
            grid[r][col] = grid[r - 1][col];
        }
    }
    for (int col = 0; col < colonne; ++col) {
        grid[0][col] = 0;
    }
}

void Grid::shiftDown(int row) {
    for (int r = row; r > 0; --r) {
        for (int col = 0; col < colonne; ++col) {
            grid[r][col] = grid[r - 1][col];
        }
    }
    for (int col = 0; col < colonne; ++col) {
        grid[0][col] = 0;
    }
}

void Grid::print() const {
    for (int i = 0; i < colonne + 2; ++i) {
        std::cout << "#";
    }
    std::cout << std::endl;

    for (int row = 0; row < righe; ++row) {
        std::cout << "#";
        for (int col = 0; col < colonne; ++col) {
            if (grid[row][col] == 0) {
                std::cout << " ";
            } else {
                std::cout << grid[row][col];
            }
        }
        std::cout << "#" << std::endl;
    }

    for (int i = 0; i < colonne + 2; ++i) {
        std::cout << "#";
    }
    std::cout << std::endl;
}

bool Grid::gameOver() const {
    for (int col = 0; col < colonne; ++col) {
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
        if (isRowFull(row)) {
            removeRow(row);
        }
    }
}

bool Grid::isCellOccupied(int row, int col) const {
    if (row >= 0 && row < righe && col >= 0 && col < colonne) {
        return grid[row][col] != 0;
    }
    return true;
}

void Grid::placeTetromino(Tetris::Tetromino& tetromino, int startRow, int startCol) {
    const int (&shape)[4][4] = tetromino.getShape();
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            if (shape[row][col] != 0) {
                set(startRow + row, startCol + col, shape[row][col]);
            }
        }
    }
}





