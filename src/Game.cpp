#include "Game.hpp"
#include "Schermate.cpp"

Game::Game() {
    srand(time(nullptr));
    this->Score = 100;
    this->start = time(0);
}

void Game::init() {
    nextShape.setRandomShape();
    shape.setRandomShape();
    this->start = time(0);
    
    //creo la finestra di gioco
    
    start_color();
    for (int i = 1; i <= 10; ++i)
        init_pair(i, i % 8 + 1, COLOR_BLACK);
    nextShape.setXY(15, 10);
    init_pair(10, COLOR_WHITE, COLOR_BLACK);
}

void Game::draw() {
    clear(); 
    grid.draw();
    attrset(COLOR_PAIR(nextShape.shapeIndex));
    shape.draw();
    attrset(COLOR_PAIR(nextShape.shapeIndex));
    nextShape.draw();
    attrset(COLOR_PAIR(10));
    string score = "Score: " + to_string(Score);
    mvprintw(5, 25, "                      ");
    mvprintw(5, 25, "%s", score.c_str());
    string timeStr = "Elapsed time: " + std::to_string(static_cast<int>(difftime(time(0), start))) + " seconds";
    mvprintw(3, 25, "%s", timeStr.c_str());
    refresh();
}

bool Game::update(int xmax, int ymax, string path) {
    bool ret = true;

    if (!shape.checkCollision(grid.grid, shape.x, shape.y + 1))
        shape.moveDown();
    else
    {
        grid.placeShape(shape);
        grid.checkLines(Score);
        shape = nextShape;
        shape.ResetXY();
        nextShape.setRandomShape();
        if (shape.checkCollision(grid.grid, shape.x, shape.y))
        {
            clear();
            this->start = difftime(time(0), start);
            game_over(xmax, ymax, path);
            napms(2500);

            ret = false;
        }
    }

    return ret;
}

void Game::handleInput() {
    int ch = getch();

    if(ch == KEY_LEFT)
        shape.moveLeft(grid.grid);
    else if(ch == KEY_RIGHT)
        shape.moveRight(grid.grid);
    else if(ch == KEY_UP)
        shape.rotateClockwise();
    else if(ch == KEY_DOWN)
        shape.rotateCounterClockwise();
}

void Game::run(int xmax, int ymax,string path) {
    bool loop = true;

    clear();

    nodelay(stdscr, TRUE);
    while (loop)
    {
        draw();
        handleInput();
        if (!update(xmax, ymax, path))
            loop = false;
        napms(300);
    }

}