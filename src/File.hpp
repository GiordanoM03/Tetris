//
// Created by mael on 10/07/24.
//

#ifndef FILE_HPP
#define FILE_HPP

#include <cstring>
#include <fstream>
#include <ncurses.h>
#include "Rank.hpp"

using namespace std;

void print_file(WINDOW* win, string path);
int num_of_columns(string path);
int num_of_rows (string path);
void write_file(string path, rank_list* list);

#endif //FILE_HPP
