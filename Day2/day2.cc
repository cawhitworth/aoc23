#include <string>
#include <regex>
#include <algorithm>

#include "day2.h"

std::vector<std::string> split_string(const std::string& s, const char c)
{
    std::vector<std::string> result;

    size_t pos = 0, prev = 0;
    while((pos = s.find(c, pos)) != std::string::npos) {
        result.push_back(s.substr(prev, pos - prev));
        pos ++;
        prev = pos;

    }
    result.push_back(s.substr(prev, pos));

    return result;
}

Game parse_line(const std::string& line)
{
    Game g;
    static std::regex re_game_line("Game (\\d)+:(.*)");
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
        Draw draw;
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

bool possible_game(const Game& g, const Draw& bag)
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