#ifndef GRID_HPP
#define GRID_HPP

class Grid {
private:
    static const int righe = 22;
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

};

#endif