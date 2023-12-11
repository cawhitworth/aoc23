#pragma once

#include <string>
#include <vector>

struct Draw {
    Draw() : red(0), green(0), blue(0) {}
    Draw(int r, int g, int b) : red(r), green(g), blue(b) {}

    int red;
    int blue;
    int green;
};

bool operator==(const Draw& lhs, const Draw& rhs);

bool operator!=(const Draw& lhs, const Draw& rhs);

struct Game {
    Game() {}
    Game(int n) : number(n) {}

    int number;
    std::vector<Draw> draws;
};

bool operator==(const Game&, const Game&);

Game parse_line(std::string line);