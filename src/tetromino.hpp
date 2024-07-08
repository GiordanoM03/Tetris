#ifndef TETROMINO_HPP
#define TETROMINO_HPP
#include <cstdlib>
#include <ctime>

class Grid; 

namespace Tetris {

class Tetromino {
private:
    int tetromino[4][4];
public:
    enum TetrominoID {
        I = 0,
        J = 1,
        L = 2,
        O = 3,
        S = 4,
        T = 5,
        Z = 6,
    };

    Tetromino(TetrominoID id);
    Tetromino(); 
    Tetromino(const Tetromino& other); 
    Tetromino& operator=(const Tetromino& other); 

    void loadTetromino(TetrominoID id);
    int randomother();
    void rotateRight();
    void moveLeft();
    void moveRight();
    bool canMoveLeft(const Grid& grid, int startRow, int startCol) const;
    bool canMoveRight(const Grid& grid, int startRow, int startCol) const;
    static Tetromino getRandomTetromino();
    void applyRandomRotations();
    const int (&getShape() const)[4][4]; 
};

} 

#endif 




