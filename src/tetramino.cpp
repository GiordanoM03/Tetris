#include "tetramino.hpp"
#include <cstdlib>
#include <iostream>
#include <conio.h>

const int Tetromino::I[4][4] = {
    {0, 0, 0, 0},
    {1, 1, 1, 1},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

const int Tetromino::J[4][4] = {
    {1, 0, 0, 0},
    {1, 1, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

const int Tetromino::L[4][4] = {
    {0, 0, 1, 0},
    {1, 1, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

const int Tetromino::O[4][4] = {
    {0, 0, 0, 0},
    {0, 1, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0}
};

const int Tetromino::S[4][4] = {
    {0, 1, 1, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

const int Tetromino::T[4][4] = {
    {0, 1, 0, 0},
    {1, 1, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

const int Tetromino::Z[4][4] = {
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

int Tetromino::random() {
    int N = rand() % 4;
    return N;
}

void Tetromino::rotateRight(int tetramino[4][4]) {
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

void Tetromino::rightarrow(int tetramino[4][4]) {
    int key = getch(); 
    if (key == 77) {
        rotateRight(tetramino);
    }
}

void rotateLeft(int tetramino[4][4]) {
    int temp[4][4];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            temp[i][j] = tetramino[i][j];
        }
    }
    
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            tetramino[3 - j][i] = temp[i][j];
        }
    }
}

void leftarrow(int tetramino[4][4]) {
    int key = _getch(); 

    if (key == 75) {
        rotateLeft(tetramino);
    }
}



