#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "day3.h"

int main(int argc, char* argv[])
{
    std::ifstream infile { argv[1] };
    std::vector<std::string> lines;

    for(std::string line; std::getline(infile, line); ) {
        lines.push_back(line);
    }

    int total = 0;
    auto s = parse_input(lines);
    for(auto p: s.actual_parts()) {
        total += std::stoi(p.number);
    }

    std::cout << "Result: " << total << std::endl;
    return 0;
}

