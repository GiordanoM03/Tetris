#include "schermate.cpp"
#include "file.cpp"

#define LOGO_PATH "./logo.txt"
#define COMMANDS_PATH "./comandi.txt"
#define RANKING_PATH "./ranking.txt"


int main(){
    int xmax, ymax;

    //schermata iniziale
    initscr();
    noecho();
    cbreak();
    getmaxyx(stdscr, ymax, xmax);

    //Scritta TETRIS
    logo(xmax, LOGO_PATH);

    //Comandi
    comandi(xmax, COMMANDS_PATH);

    //Classifica
    ranking(xmax, RANKING_PATH);

    //menu
    int choice = menu(xmax);

    getch();

    endwin();    

    return 0;
}