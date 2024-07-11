//
// Created by mael on 09/07/24.
//

#include <vector>
#include <sstream>
#include <fstream>

#include "Rank.hpp"

rank_list *ranking_list(string path, rank_list *list) {

    rank_list* temp = list;

    ifstream in_file;
    in_file.open(path);

    vector<string> row;
    string line, word;

    while(in_file >> line) {
        row.clear();

        stringstream s(line);

        while (getline(s, word, ','))
            row.push_back(word);

        rank_list* element = new rank_list;

        element->name = row[0];
        element->points = stoi(row[1]);
        element->level = stoi(row[2]);
        element->rows = stoi(row[3]);
        element->minutes = stoi(row[4]);
        element->seconds = stoi(row[5]);

        temp->next = element;
        temp = temp->next;
    }

    return list;
}

void print_list(WINDOW* win, rank_list *list, bool homescreen, int rank) {
    rank_list* temp = list;
    int ymax = getmaxy(win);

    if (homescreen) {
        wprintw(win, "                    CLASSIFICA\n");
        for (int i = 0; i < 5 && temp != nullptr; i++) {
            wprintw(win, "%d. %s -> Punteggio: %d, Livello: %d, Righe: %d, Tempo: %d'%d''", rank, temp->name.data(),
                temp->points, temp->level, temp->rows, temp->minutes, temp->seconds);
            temp = temp->next;
            rank++;
        }
    } else {
        while (temp != nullptr && rank < ymax) {
            wprintw(win, "%d. %s -> Punteggio: %d, Livello: %d, Righe: %d, Tempo: %d'%d''\n", rank, temp->name.data(),
                temp->points, temp->level, temp->rows, temp->minutes, temp->seconds);

            temp = temp->next;
            rank++;
        }
    }
}
