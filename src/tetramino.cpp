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


//nella funzione di gioco si implementerà mettendo anche i tasti per cui valgono le funzioni sottostanti

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









