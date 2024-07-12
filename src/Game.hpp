#ifndef GAME_HPP
#define GAME_HPP

#include <ctime>
#include <string>

#include "Grid.cpp"

class Game {
private:
    Grid grid;
    Shape shape;
    Shape nextShape;

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