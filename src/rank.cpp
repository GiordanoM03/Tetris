#include "rank.hpp"

Rank::Rank() {
    strcpy(this->name, NULL);
    this->points = 0;
    this->level = 0;
    this->rows = 0;
    this->minutes = 0;
    this->seconds = 0;
}

Rank::Rank(char* name, int points, int level, int rows, int minutes, int seconds) {
    strcpy(this->name, name);
    this->points = points;
    this->level = level;
    this->rows = rows;
    this->minutes = minutes;
    this->seconds = seconds;
}

