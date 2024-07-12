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
        element->seconds = stoi(row[2]);

        temp->next = element;
        temp = temp->next;
    }

    return list;
}

rank_list* add_element(rank_list* list, string name, int points, int seconds) {
    rank_list* prev = list;
    rank_list* temp = list->next;
    
    rank_list* element;
    element->name = name;
    element->points = points;
    element->seconds = seconds;
    element->next = NULL;

    while (temp != NULL) {
        if (element->points > temp->points) {
            prev->next = element;
            element->next = temp;
            return list;
        }

        prev = temp;
        temp = temp->next;
    }

    prev->next = element;

    return list;
    
}

void print_list(WINDOW* win, rank_list *list, bool homescreen, int rank) {
    rank_list* temp = list;
    int ymax = getmaxy(win);

    if (homescreen) {
        wprintw(win, "                    CLASSIFICA\n");
        for (int i = 0; i < 5 && temp != nullptr; i++) {
            wprintw(win, "%d. %s -> Punteggio: %d, Tempo: %d''\n",
                rank,
                temp->name.data(),
                temp->points, 
                temp->seconds);
            temp = temp->next;
            rank++;
        }
    } else {
        while (temp != nullptr && rank < ymax) {
            wprintw(win, "%d. %s -> Punteggio: %d Tempo: %d''\n",
                rank,
                temp->name.data(),
                temp->points,
                temp->seconds);

            temp = temp->next;
            rank++;
        }
    }
}
