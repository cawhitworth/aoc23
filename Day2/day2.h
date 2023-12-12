#pragma once

#include <string>
#include <vector>

struct BallSet {
    BallSet() : red(0), green(0), blue(0) {}
    BallSet(const int r, const int g, const int b) : red(r), green(g), blue(b) {}

    int power() {
        return red * green * blue;
    }

    int red;
    int blue;
    int green;
};

bool operator==(const BallSet& lhs, const BallSet& rhs);

bool operator!=(const BallSet& lhs, const BallSet& rhs);

std::ostream& operator<<(std::ostream& os, const BallSet& ballset);

struct Game {
    Game() {}
    Game(const int n) : number(n) {}

    int number;
    std::vector<BallSet> draws;
};

bool operator==(const Game&, const Game&);

Game parse_line(const std::string& line);

bool possible_game(const Game& g, const BallSet& bag);

BallSet minimum_possible(const Game& g);