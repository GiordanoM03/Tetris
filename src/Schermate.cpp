//
// Created by mael on 10/07/24.
//

#include "File.cpp"
#include "Schermate.hpp"

void logo(int xmax, string logo_path){
    WINDOW* logo = newwin(8, 91, 5, (xmax/2)-46);
    refresh();
    print_file(logo, logo_path);
    wrefresh(logo);
}

void comandi(int xmax, string commands_path){
    WINDOW* commands = newwin(7, (xmax/2)-10, 20, 10);
    refresh();
    print_file(commands, commands_path);
    wrefresh(commands);
}

void ranking(int xmax, rank_list* list, bool homescreen){
    WINDOW* ranking = newwin(9, (xmax/2)-10, 20, (xmax/2));
    refresh();
    print_list(ranking, list);
    wrefresh(ranking);
}

void game_over(int xmax, int ymax, string commands_path){
    WINDOW* game_over = newwin(8, 91, (ymax/2)-4, (xmax-91)/2);
    refresh();
    print_file(game_over, commands_path);
    wrefresh(game_over);
}

string player_name(int xmax, int ymax) {

    WINDOW* in_win = newwin(1, ymax, 0, xmax);
    WINDOW* out_win = newwin(5, ymax, 0, 0);

    bool loop = true;

    keypad(in_win, true);
    box(out_win, 0, 0);
    mvwprintw(out_win, 1, 1, "Inserisci il tuo nome\n");
    wrefresh(out_win);
    char ch = '\0';

    string name = "";
    
    while (loop) {
        ch = wgetch(in_win);
        if (ch == '\n') {
            loop = false;
        } else {
            name.push_back(ch);
            mvwprintw(out_win, 3, 1, "%s\n", name.data());
            wrefresh(out_win);
        }
    }

    return name;
}

int menu(int xmax) {
    WINDOW* menu = newwin(3, xmax-20, 30, 10);
    box(menu, 0, 0);
    refresh();
    wrefresh(menu);

    keypad(menu, true);

    string choices[3] = {"*Nuova Partita", "*Classifica", "*Esci"};
    int choice = 0;
    int highlight = 0;

    while(choice != 10){
        for (int i = 0; i < 3; i++)
        {
            if (i == highlight)
                wattron(menu, A_REVERSE);
            mvwprintw(menu, 1, ((xmax/3)*i)+1, "%s", choices[i].c_str());
            wattroff(menu, A_REVERSE);
        }

        choice = wgetch(menu);

        if (choice == KEY_LEFT){
            highlight--;
            if (highlight == -1)
                highlight = 0;
        }else if (choice == KEY_RIGHT){
            highlight++;
            if (highlight == 3)
                highlight = 2;
        }
    }

    return highlight;
}