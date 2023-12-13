#include <iostream>
#include <fstream>
#include <string>
#include "day4.h"

int main(int argc, char* argv[])
{
    std::ifstream input { argv[1] };
    
    int total = 0;
    std::vector<Card> cards;
    for(std::string line; std::getline(input, line); ) {
        Card c(line);
        std::cout << c.card << std::endl;
        total += c.score();
        cards.push_back(c);
    }

    auto score = play(cards);

    std::cout << "Part 1: " << total << std::endl;
    std::cout << "Part 2: " << score << std::endl;
    return 0;
}

