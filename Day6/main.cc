#include <iostream>
#include <fstream>
#include <string>
#include "day6.h"

int main(int argc, char* argv[])
{
    std::ifstream input { argv[1] };

    std::string line;
    std::getline(input, line);
    auto times = parse_times(line);
    auto times_bignum = parse_times_bignum(line);
    std::getline(input, line);
    auto distances = parse_distances(line);
    auto distances_bignum = parse_distances_bignum(line);

    int result = 0;
    for(int i = 0; i < times.size(); i++) {
        int r = winning_ways(times[i], distances[i]);
        if (result == 0) { result = r;} else { result *= r; }
    }

    std::cout << "Result: " << result << std::endl;

    std::cout << "Result: " << winning_ways_quadratic(times_bignum, distances_bignum) << std::endl;

    return 0;
}

