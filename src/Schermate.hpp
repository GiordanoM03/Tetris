//
// Created by mael on 10/07/24.
//

#ifndef SCHERMATE_HPP
#define SCHERMATE_HPP

#include "Rank.hpp"

void logo(int xmax, string logo_path);
void comandi(int xmax, string commands_path);
void ranking(int xmax, rank_list* list, bool homescreen = true);
void game_over(int xmax, int ymax, string path);
string palyer_name(int xmax, int ymax);
int menu(int xmax);

#endif //SCHERMATE_HPP
