#include <string>
#include <regex>

#include "day2.h"

Game parse_line(std::string line)
{
    Game g;
    std::regex re_game_line("Game (\\d):(.*)");
    std::smatch mr;
    if (!std::regex_match(line, mr, re_game_line)) {
        g.number = -1;
        return g;
    }
    auto game_number = mr[1].str();
    g.number = atoi(game_number.c_str());

    std::regex re_game_draws("(.*);")

    return g;
}

bool operator==(const Draw& lhs, const Draw& rhs) {
    return lhs.red == rhs.red &&
           lhs.green == rhs.green &&
           lhs.blue == rhs.blue;
}

bool operator!=(const Draw& lhs, const Draw& rhs) {
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