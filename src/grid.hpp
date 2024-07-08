#ifndef GRID_HPP
#define GRID_HPP

#include "tetromino.hpp"

class Grid {
private:
    int righe;
    int colonne;
    int grid[23][10];  // Fixed size array

public:
    Grid(int rows = 23, int cols = 10);
    Grid(const Grid& other); // Copy constructor
    Grid& operator=(const Grid& other); // Copy assignment operator
    void clear();
    void set(int row, int col, int value);
    int get(int row, int col) const;
    bool isRowFull(int row) const;
    void removeRow(int row);
    void shiftDown(int row);
    void print() const;
    bool gameOver() const;
    bool canPlaceTetromino(const int tetromino[4][4], int startRow, int startCol) const;
    void clearFullRows();
    bool isCellOccupied(int row, int col) const;
    void placeTetromino(Tetris::Tetromino& tetromino, int startRow, int startCol);
    int getColCount() const { return colonne; }
};

#endif // GRID_HPP




 
