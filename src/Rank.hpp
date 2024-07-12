//
// Created by mael on 09/07/24.
//

#ifndef RANK_HPP
#define RANK_HPP

#include <string>
#include <cstring>
#include <ncurses.h>
using namespace std;

struct rank_list {
    string name;
    int points;
    int seconds;
    rank_list* next;
};

rank_list* ranking_list(string path, rank_list* list);
rank_list* add_element(rank_list* list, string name, int points, int seconds);

void print_list(WINDOW* win, rank_list* list, bool homescreen = true, int rank = 1);

#endif //RANK_HPP
