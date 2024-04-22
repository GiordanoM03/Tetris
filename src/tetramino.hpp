#ifndef TETROMINO_HPP
#define TETROMINO_HPP

class Tetromino {
private:
    static const int I[4][4];
    static const int J[4][4];
    static const int L[4][4];
    static const int O[4][4];
    static const int S[4][4];
    static const int T[4][4];
    static const int Z[4][4];
public:   

    enum TetrominoID {
    I = 1,
    J = 2,
    L = 3,
    O = 4,
    S = 5,
    T = 6,
    Z = 7,
};

    int random(); 
    int randomother();  //genera un numero da 0 a 3 per determinare con che rotazione buttare il tetramino iniziale
    //le funzioni sotto servono a ruorate, in input c'è ora una matrice 4x4 generica, poi dovra essere messa quella che viene scelta randomly
    void rotateRight(int tetramino[4][4]);
    void moveLeft(int tetramino[4][4]);
    void moveRight(int tetramino[4][4]);


};

#endif