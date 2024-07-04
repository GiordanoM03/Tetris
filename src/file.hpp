#ifndef FILE_H
#define FILE_H

#include <cstring>
#include <fstream>
#include <ncurses.h>
#include <vector>
#include <sstream>

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

void read_csv(string path) {
    fstream in_file;
    in_file.open(path);
    
    vector<string> row;
    string line, word, temp;

    while (!in_file.eof()) {
        row.clear();

        getline(in_file, line);

        stringstream s(line);

        while (getline(s, word, ','))
            row.push_back(word);

    }    

    in_file.close();
}

int num_of_columns(string path){
    ifstream in_file;
    in_file.open(path);
    
    string line;
    getline(in_file, line);
    

    in_file.close();

    return line.length();
}

int num_of_rows (string path) {
    int num_rows = 0;
    string line;

    ifstream in_file;
    in_file.open(path);

    while(getline(in_file, line))
        num_rows++;

    return num_rows;
}

void write_file(string path){
    ofstream out_file;
    out_file.open(path);

    //TODO

    out_file.close();
}

#endif