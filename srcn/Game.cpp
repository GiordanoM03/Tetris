#include "Game.hpp"

Game::Game()
{
    srand(time(nullptr));
    Score = 100;
}

void Game::init()
{
    nextShape.setRandomShape();
    shape.setRandomShape();
    initscr();
    noecho();
    cbreak();
    curs_set(FALSE);
    start_color();
    for (int i = 1; i <= 10; ++i)
        init_pair(i, i % 8 + 1, COLOR_BLACK);
    nextShape.setXY(15, 10);
    init_pair(10, COLOR_WHITE, COLOR_BLACK);
}

void Game::end()
{
    endwin();
}

void Game::draw()
{
    clear();
    grid.draw();
    attrset(COLOR_PAIR(nextShape.shapeIndex));
    shape.draw();
    attrset(COLOR_PAIR(nextShape.shapeIndex));
    nextShape.draw();
    std::string score = "Score: " + std::to_string(Score);
    mvprintw(5, 25, "%s", score.c_str());
    refresh();
}

void Game::update()
{
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
            mvprintw(GRID_HEIGHT / 2, (GRID_WIDTH / 2 - 5) * 2, "Game Over");
            refresh();
            napms(2000);
            end();
            exit(0);
        }
    }
}

void Game::handleInput()
{
    int ch = getch();
    switch (ch)
    {
    case 'a':
        shape.moveLeft(grid.grid);
        break;
    case 'd':
        shape.moveRight(grid.grid);
        break;
    case 'w':
        shape.rotateClockwise();
        break;
    case 's':
        shape.rotateCounterClockwise();
        break;
    }
}

void Game::run()
{
    nodelay(stdscr, TRUE);
    while (true)
    {
        draw();
        handleInput();
        update();
        napms(300);
    }
}
