#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdint.h>
#include "day7.h"

int main(int argc, char* argv[])
{
    std::ifstream input { argv[1] };
    
    std::vector<Hand> hands;
    for(std::string line; std::getline(input, line); ) {
        hands.push_back(Hand::from_with_jokers(line));
    }

    std::sort(hands.begin(), hands.end(), Hand::compare_with_jokers );

    int rank = 1;
    uint64_t score = 0;
    for(auto hand: hands)
    {
        score += (uint64_t)(hand.bid * rank);
        rank ++;
    }

    std::cout << "Result: " << score << std::endl;
    return 0;
}

