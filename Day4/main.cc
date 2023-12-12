#include <iostream>
#include <fstream>
#include <string>
#include "day4.h"

int main(int argc, char* argv[])
{
    std::ifstream input { argv[1] };
    
    int total = 0;
    for(std::string line; std::getline(input, line); ) {
        Card c(line);
        std::cout << c.card << std::endl;
        total += c.score();
    }

    std::cout << "Result: " << total << std::endl;
    return 0;
}

