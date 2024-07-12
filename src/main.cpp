#include "Game.cpp"

#include <iostream>

#define LOGO_PATH "../file_schermate/logo.txt"
#define COMMANDS_PATH "../file_schermate/comandi.txt"
#define RANKING_PATH "../file_schermate/ranking.csv"
#define GAME_OVER_PATH "../file_schermate/game_over.txt"

int main() {
    int xmax, ymax, choice;

    choice = 0;

    rank_list element;

    //Creo la lista con gli elementi della classifica
    rank_list *list = new rank_list;
    list = ranking_list(RANKING_PATH, list);

    //avvio lo schermo
    initscr();
    noecho();
    cbreak();

    keypad(stdscr, true);

    getmaxyx(stdscr, ymax, xmax);

    while (choice != 2) {
        //pulisco lo schermo
        clear();

        //Creo la schermata iniziale

        //Scritta TETRIS
        logo(xmax, LOGO_PATH);

        //Comandi
        comandi(xmax, COMMANDS_PATH);

        //Classifica
        ranking(xmax, list->next);

        //Menu
        choice = menu(xmax);

        if (choice == 0){
            //apro la schermata di gioco
            Game game;
            game.init();
            game.run(xmax, ymax, GAME_OVER_PATH);
            game_over(xmax, ymax, GAME_OVER_PATH);
            clear();
            refresh();

            //prendo il nome del giocatore
            string name;
            name = player_name(xmax, ymax);
            clear();
            refresh();

            list = add_element(list, name, game.Score, game.start);
        }else if (choice == 1) {
            //Pulisco lo schermo per poter stampare tutta la classifica (almeno fino alla fine dello schermo)
            clear();
            printw("                   CLASSIFICA GENERALE\n");
            print_list(stdscr, list->next, false);
            getch();
        }

    }

    write_file(RANKING_PATH, list);

    endwin();

    return 0;
}
