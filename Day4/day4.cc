#include <regex>

#include "utils.h"
#include "day4.h"

Card::Card(const std::string& line)
{
    auto split = split_string(line, ':');
    static std::regex re_card("Card\\s+(\\d+)");
    std::smatch mr;
    if (!std::regex_match(split[0], mr, re_card)) {
        return;
    }
    this->card = std::stoi(mr[1].str());

    split = split_string(split[1], '|');
    auto winning_str = split[0];
    auto numbers_str = split[1];
    this->winners = numbers_from(winning_str);
    this->numbers = numbers_from(numbers_str);
}

int Card::score()
{
    int score = 0;
    for(auto n: numbers) {
        if (std::find(winners.begin(), winners.end(), n) != winners.end())
        {
            if (score == 0) { score = 1;} else {score *= 2;}
        }
    }
    return score;
}