#pragma once
#include <string>
#include <vector>

struct Card
{
    Card(const std::string& line);

    int score();

    int card;
    std::vector<int> winners;
    std::vector<int> numbers;
};