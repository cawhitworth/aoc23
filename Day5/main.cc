#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "day5.h"

int main(int argc, char* argv[])
{
    std::ifstream input { argv[1] };
    std::vector<std::string> lines;

    for(std::string line; std::getline(input, line); ) {
        lines.push_back(line);
    }

    Almanac a(lines);
    long long lowest = -1;
    for(auto s: a.seeds) {
        long long result = a.map_through(s);
        if (result < lowest || lowest == -1) {
            lowest = result;
        }
    }

    std::cout << "Result: " << lowest << std::endl;
    return 0;
}

