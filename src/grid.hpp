#ifndef GRID_HPP
#define GRID_HPP

class Grid {
private:
    static const int righe = 23;
    static const int colonne = 10;
    int grid[righe][colonne];
 public:
    Grid(); 
    void clear(); //mette tutti i valori a 0
    void set(int riga, int colonna, int value);   
    int get(int riga, int colonna) const;
    bool isrowfull(int riga) const;
    void removerow(int riga);
    void shiftdown(int riga);
    void print() const;
    static bool gameOver(int grid[21][10]);
    bool canPlaceTetromino(const int tetromino[4][4], int startRow, int startCol) const;
    void clearFullRows();
     bool isCellOccupied(int row, int col) const;
private:
    static const int righe = 20;  
    static const int colonne = 10; 
    int grid[righe][colonne];  
};

#endif