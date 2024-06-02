#ifndef FILE_H
#define FILE_H

#include <string>
#include <fstream>
#include <ncurses.h>

using namespace std;

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

void write_file(string path){
    ofstream out_file;
    out_file.open(path);

    //TODO

    out_file.close();
}

#endif