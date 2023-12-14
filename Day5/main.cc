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
    // for(auto s: a.seeds) {
    //     long long result = a.map_through(s);
    //     if (result < lowest || lowest == -1) {
    //         lowest = result;
    //     }
    // }

    for(long long pair = 0; pair < a.seeds.size(); pair += 2)
    {
        for(long long seed = a.seeds[pair]; seed < a.seeds[pair] + a.seeds[pair+1]; seed++)
        {
            long long result = a.map_through(seed);
            if (result < lowest || lowest == -1) {
                lowest = result;
            }
        }
    }

    std::cout << "Result: " << lowest << std::endl;
    return 0;
}

