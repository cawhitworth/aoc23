#pragma once
#include <string>
#include <vector>

struct Card
{
    Card(const std::string& line);

    int score() const;
    int matches() const;

    int card;
    std::vector<int> winners;
    std::vector<int> numbers;
};

int play(const std::vector<Card>& cards);