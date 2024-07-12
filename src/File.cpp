//
// Created by mael on 10/07/24.
//

#include "File.hpp"
#include "Rank.cpp"

void print_file(WINDOW* win, string path){
    ifstream in_file;
    in_file.open(path);
    char ch;
    while (!in_file.eof())
    {
        ch = in_file.get();
        if (ch != EOF){
            wprintw(win, "%c", ch);
        }
    }

    in_file.close();
}

void write_file(string path, rank_list* list){
    ofstream out_file;
    out_file.open(path);

    rank_list* temp = list->next;

    while (temp) {
        out_file << temp->name << ","
                 << temp->points << ","
                 << temp->seconds << "\n";

        temp = temp->next;
    }

    out_file.close();
}
