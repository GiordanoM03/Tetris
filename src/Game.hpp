#ifndef GAME_HPP
#define GAME_HPP

<<<<<<< HEAD
#include "Grid.hpp"
#include "Shape.hpp"
#include <string>

class Game
{
=======
#include <ctime>
#include <string>

#include "Grid.cpp"

class Game {
>>>>>>> cddcac4384ead00e599165e15a19c436c24a775d
private:
    Grid grid;
    Shape shape;
    Shape nextShape;
<<<<<<< HEAD
    int Score;

public:
    Game();
    void init();
    void end();
    void draw();
    void update();
    void handleInput();
    void run();
};

#endif 
=======

public:
    int Score;
    time_t start;

    Game();
    void init();
    void draw();
    bool update(int xmax, int ymax, string path);
    void handleInput();
    void run(int xmax, int ymax, string path);
};

#endif //GAME_HPP
>>>>>>> cddcac4384ead00e599165e15a19c436c24a775d
