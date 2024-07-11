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
                highlight = 1;
        }
    }

    return highlight;
}