#include <string>
#include <iostream>
#include <regex>
#include <algorithm>

#include <utils.h>
#include "day2.h"

Game parse_line(const std::string& line)
{
    Game g;
    static std::regex re_game_line("Game (\\d+):(.*)");
    std::smatch mr;
    if (!std::regex_match(line, mr, re_game_line)) {
        g.number = -1;
        return g;
    }
    auto game_number = mr[1].str();
    g.number = atoi(game_number.c_str());

    auto draws = split_string(mr[2], ';');

    static std::regex re_ball("(\\d+) (red|green|blue)");
    for(auto draw_string: draws) {
        BallSet draw;
        auto balls = split_string(draw_string, ',');
        for(auto ball: balls) {
            if (!std::regex_search(ball, mr, re_ball)) {
                g.number = -1;
                return g;
            }
            int ball_count = atoi(mr[1].str().c_str());
            if (mr[2] == "red") {
                draw.red = ball_count;
            } else if (mr[2] == "blue") {
                draw.blue = ball_count;
            } else if (mr[2] == "green") {
                draw.green = ball_count;
            } else {
                g.number = -1;
                return g;
            }
        }
        g.draws.push_back(draw);
    }

    return g;
}

bool possible_game(const Game& g, const BallSet& bag)
{
    for (auto d: g.draws) {
        if (d.red > bag.red ||
            d.green > bag.green ||
            d.blue > bag.blue) {
            return false;
        }
    }

    return true;
}

BallSet minimum_possible(const Game& g)
{
    BallSet minimum;
    for(auto draw: g.draws) {
        if (draw.red > minimum.red) {
            minimum.red = draw.red;
        }
        if (draw.green > minimum.green) {
            minimum.green = draw.green;
        }
        if (draw.blue > minimum.blue) {
            minimum.blue = draw.blue;
        }
    }
    return minimum;
}

std::ostream& operator<<(std::ostream& os, const BallSet& ballset)
{
    os << "BallSet { Red: " << ballset.red << ", Green: " << ballset.green << ", Blue: " << ballset.blue << "}";
    return os;
}

bool operator==(const BallSet& lhs, const BallSet& rhs) {
    return lhs.red == rhs.red &&
           lhs.green == rhs.green &&
           lhs.blue == rhs.blue;
}

bool operator!=(const BallSet& lhs, const BallSet& rhs) {
    return !(lhs == rhs);
}

bool operator==(const Game& lhs, const Game& rhs)
{
    if (lhs.number != rhs.number) {
        return false;
    }

    if (lhs.draws.size() != rhs.draws.size()) {
        return false;
    }

    for(int d = 0; d < lhs.draws.size(); d++) {
        if (lhs.draws[d] != rhs.draws[d]) {
            return false;
        }
    }

    return true;
}