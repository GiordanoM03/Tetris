#include "tetromino.hpp"
#include "grid.hpp"
#include <iostream>
#include <cstdio>

#define TETRAMINI_DIR "Tetramini/"

namespace Tetris {

Tetromino::Tetromino(TetrominoID id) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            tetromino[i][j] = 0;
        }
    }
    loadTetromino(id);
}

Tetromino::Tetromino() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            tetromino[i][j] = 0;
        }
    }
}

Tetromino::Tetromino(const Tetromino& other) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            tetromino[i][j] = other.tetromino[i][j];
        }
    }
}

Tetromino& Tetromino::operator=(const Tetromino& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                tetromino[i][j] = other.tetromino[i][j];
            }
        }
    }
    return *this;
}

void Tetromino::loadTetromino(TetrominoID id) {
    const char* filename;
    switch (id) {
        case I: filename = TETRAMINI_DIR "t1.txt"; break;
        case J: filename = TETRAMINI_DIR "t2.txt"; break;
        case L: filename = TETRAMINI_DIR "t3.txt"; break;
        case O: filename = TETRAMINI_DIR "t4.txt"; break;
        case S: filename = TETRAMINI_DIR "t5.txt"; break;
        case T: filename = TETRAMINI_DIR "t6.txt"; break;
        case Z: filename = TETRAMINI_DIR "t7.txt"; break;
        default: return;
    }

    FILE* file = fopen(filename, "r");
    if (!file) {
        return;
    }

    char line[5];
    int row = 0;
    while (fgets(line, sizeof(line), file) && row < 4) {
        for (int col = 0; col < 4; ++col) {
            if (line[col] == '0' || line[col] == '1') {
                tetromino[row][col] = line[col] - '0';
            } else {
                tetromino[row][col] = 0;
            }
        }
        ++row;
    }
    fclose(file);
}

int Tetromino::randomother() {
    return rand() % 4;
}

void Tetromino::rotateRight() {
    int temp[4][4];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            temp[i][j] = tetromino[i][j];
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            tetromino[j][3 - i] = temp[i][j];
        }
    }
}

void Tetromino::moveLeft() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (tetromino[i][j] != 0 && (j == 0 || tetromino[i][j - 1] != 0)) {
                return;
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (tetromino[i][j] != 0) {
                tetromino[i][j] = 0;
                tetromino[i][j - 1] = 1;
            }
        }
    }
}

void Tetromino::moveRight() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (tetromino[i][j] != 0 && (j == 3 || tetromino[i][j + 1] != 0)) {
                return;
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 3; j >= 0; --j) {
            if (tetromino[i][j] != 0) {
                tetromino[i][j] = 0;
                tetromino[i][j + 1] = 1;
            }
        }
    }
}

Tetromino Tetromino::getRandomTetromino() {
    static bool initialized = false;
    if (!initialized) {
        srand(time(0));
        initialized = true;
    }
    TetrominoID randomID = static_cast<TetrominoID>(rand() % 7);
    Tetromino tetromino(randomID);
    tetromino.applyRandomRotations();
    return tetromino;
}

void Tetromino::applyRandomRotations() {
    int rotations = rand() % 4;
    for (int i = 0; i < rotations; ++i) {
        rotateRight();
    }
}

bool Tetromino::canMoveLeft(const Grid& grid, int startRow, int startCol) const {
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            if (tetromino[row][col] != 0) {
                int newCol = startCol + col - 1;
                if (newCol < 0 || grid.isCellOccupied(startRow + row, newCol)) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Tetromino::canMoveRight(const Grid& grid, int startRow, int startCol) const {
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            if (tetromino[row][col] != 0) {
                int newCol = startCol + col + 1;
                if (newCol >= grid.getColCount() || grid.isCellOccupied(startRow + row, newCol)) {
                    return false;
                }
            }
        }
    }
    return true;
}

const int (&Tetromino::getShape() const)[4][4] {
    return tetromino;
}

}  

