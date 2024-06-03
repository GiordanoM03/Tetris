#ifndef TETROMINO_HPP
#define TETROMINO_HPP

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

    int random();
    int randomother();
    void rotateRight(int tetramino[4][4]);
    void moveLeft(int tetramino[4][4]);
    void moveRight(int tetramino[4][4]);
    void loadTetromino(TetrominoID id);

static Tetromino getRandomTetromino();  
    void applyRandomRotations();  

};

#endif
