#include <iostream>
#include <fstream>
#include <string>
#include "day1.h"

int main(int argc, char* argv[])
{
    std::ifstream input { argv[1] };
    
    int total = 0;

    for(std::string line; std::getline(input, line); ) {
        auto line_checksum = process_line_part2(line);
        total += line_checksum;
    }
    std::cout << "Day1: " << total << std::endl;
    return 0;
}

