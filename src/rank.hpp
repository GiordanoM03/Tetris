#ifndef RANK_HPP
#define RANK_HPP

#include <cstring>
using namespace std;

class Rank {
    protected:
        char* name;
        int points;
        int level;
        int rows;
        int minutes;
        int seconds;

    public:
        Rank ();
        Rank (char* name, int points, int level, int rows, int minutes, int seconds);
};

#endif