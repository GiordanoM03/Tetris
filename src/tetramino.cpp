#include "tetramino.hpp"
#include <cstdlib>
#include <iostream>
#include <conio.h>

#define TETRAMINI_DIR "Tetramini/"

Tetromino::Tetromino(TetrominoID id) {
    loadTetromino(id);
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
    int N = rand() % 4;
    return N;
}

void Tetromino::rotateRight(int tetramino[4][4]) {
    int key = _getch();
    if (key == 72) { 
        int temp[4][4];
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                temp[i][j] = tetramino[i][j];
            }
        }
     
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                tetramino[j][3 - i] = temp[i][j];
            }
        }
    }
}

void Tetromino::moveLeft(int tetramino[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (tetramino[i][j] != 0 && (j == 0 || tetramino[i][j - 1] != 0)) {
                return;
            }
        }
    }
    
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (tetramino[i][j] != 0) {
                tetramino[i][j] = 0;
                tetramino[i][j - 1] = 1;
            }
        }
    }
}

void Tetromino::moveRight(int tetramino[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (tetramino[i][j] != 0 && (j == 3 || tetramino[i][j + 1] != 0)) {
                return;
            }
        }
    }
    
    for (int i = 0; i < 4; ++i) {
        for (int j = 3; j >= 0; --j) {
            if (tetramino[i][j] != 0) {
                tetramino[i][j] = 0;
                tetramino[i][j + 1] = 1;
            }
        }
    }
}


Tetromino Tetromino::getRandomTetromino() {
    srand(time(0));
    TetrominoID randomID = static_cast<TetrominoID>(rand() % 7); 
    Tetromino tetromino(randomID);
    tetromino.applyRandomRotations();
    return tetromino;
}

void Tetromino::applyRandomRotations() {
    srand(time(0));
    int rotations = rand() % 4 + 1; 
    for (int i = 0; i < rotations; ++i) {
        rotateRight(tetromino);
    }
}





