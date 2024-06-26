#include "grid.hpp"
#include <iostream>

Grid::Grid() {
    clear(); 
}

void Grid::clear() {
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {      //pulisce la grid mettendo tutto a 0
            grid[i][j] = 0;
        }
    }
}

void Grid::set(int row, int col, int value) {
    if (row >= 0 && row < righe && col >= 0 && col < colonne) {   //serve per mettere un value in una posizione specifica della matrice grid
        grid[row][col] = value;
    }
}

int Grid::get(int row, int col) const {
    if (row >= 0 && row < righe && col >= 0 && col < colonne) {   //serve per determinare che value c'è nella posizione rowxcolumn
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
        for (int colonna = 0; colonna < colonne; ++colonna) {     //da capire se funge
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
        if (grid[20][col] != 0) {
            return true;
        }
    }
    return false;
}