#include <regex>
#include <numeric>

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

int Card::score() const
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

int Card::matches() const
{
    return std::accumulate(
        numbers.begin(), numbers.end(), 0, 
        [=](const int total, const int number)
        {
            if (std::find(winners.begin(), winners.end(), number) != winners.end()) {
                return total + 1;
            } else {
                return total;
            }
        });
}

int play(const std::vector<Card>& cards)
{
    std::vector<int> count;
    count.resize(cards.size());
    std::fill(count.begin(), count.end(), 1);

    int card_index = 0;
    while(card_index < cards.size())
    {
        int copies = count[card_index];
        int matches = cards[card_index].matches();
        if (matches > 0) {
            for(int index = card_index + 1; index <= card_index + matches; index++) {
                if (index < cards.size()) {
                    count[index] += copies;
                }
            }
        }
        card_index++;
    }

    return std::accumulate(count.begin(), count.end(), 0);
}