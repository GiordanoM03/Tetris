#include <ncurses.h>
#include "schermate.hpp"
#include "file.hpp"
#include "grid.hpp"
#include "tetromino.hpp"
#include "timer.hpp"

#define LOGO_PATH "./logo.txt"
#define COMMANDS_PATH "./comandi.txt"
#define RANKING_PATH "./ranking.txt"

void start_game();

int main() {
    int xmax, ymax;

    
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE); 
    getmaxyx(stdscr, ymax, xmax);

    logo(xmax, LOGO_PATH);

    comandi(xmax, COMMANDS_PATH);

    ranking(xmax, RANKING_PATH);

    int choice = menu(xmax);

    if (choice == 0) {
        start_game();
    } else if (choice == 1) {
        
    }

    getch();
    endwin();

    return 0;
}

void start_game() {
    int xmax, ymax;
    getmaxyx(stdscr, ymax, xmax);

    int grid_height = 23;
    int grid_width = 10;
    int grid_start_y = 5;
    int grid_start_x = (xmax / 2) - (grid_width / 2);

    WINDOW* grid_win = newwin(grid_height, grid_width, grid_start_y, grid_start_x);
    wborder(grid_win, '#', '#', '#', '#', '#', '#', '#', '#');  
    wrefresh(grid_win);

    Grid grid(grid_height, grid_width);
    Tetris::Tetromino tetromino = Tetris::Tetromino::getRandomTetromino();
    Timer timer(grid, tetromino);

    timer.start();

    while (true) {
        int ch = getch();
        switch (ch) {
            case KEY_LEFT:
                if (tetromino.canMoveLeft(grid, tetromino.getRow(), tetromino.getCol())) {
                    tetromino.moveLeft();
                }
                break;
            case KEY_RIGHT:
                if (tetromino.canMoveRight(grid, tetromino.getRow(), tetromino.getCol())) {
                    tetromino.moveRight();
                }
                break;
            case KEY_UP:
                tetromino.rotateRight();
                break;
            case KEY_DOWN:
                tetromino.rotateLeft(); 
                break;
            case ' ':
                while (grid.canPlaceTetromino(tetromino.getShape(), tetromino.getRow() + 1, tetromino.getCol())) {
                    tetromino.setPosition(tetromino.getRow() + 1, tetromino.getCol());
                }
                break;
            case 'q':
            case 'Q':
                return;
        }

        
        werase(grid_win);  
        wborder(grid_win, '#', '#', '#', '#', '#', '#', '#', '#');  
        grid.print();  
        wrefresh(grid_win); 
    }
}
