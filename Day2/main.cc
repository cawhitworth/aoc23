#include <iostream>
#include <fstream>
#include <string>
#include "day2.h"

int main(int argc, char* argv[])
{
    std::ifstream input { argv[1] };
    
    BallSet bag(12, 13, 14);
    int total = 0;

    for(std::string line; std::getline(input, line); ) {
        Game g = parse_line(line);
        if (g.number == -1) {
            std::cout << "Parse error: " << line << std::endl;
        }
        // if (possible_game(g, bag)) {
        //     total += g.number;
        //     std::cout << "Game " << g.number << " is possible" << std::endl;
        // }
        auto bs = minimum_possible(g);
        total += bs.power();
    }

    std::cout << "Result: " << total << std::endl;
    return 0;
}

