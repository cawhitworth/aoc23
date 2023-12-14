#include <algorithm>
#include <cmath>
#include <ranges>

#include "day6.h"
#include "utils.h"

std::vector<int> parse_line(std::string line, std::string prefix)
{
    auto split = split_string(line, ':');
    if (split[0] != prefix) {
        return std::vector<int>();
    }

    return numbers_from(split[1]);
}

std::vector<int> parse_times(std::string line)
{
    return parse_line(line, "Time");
}

std::vector<int> parse_distances(std::string line)
{
    return parse_line(line, "Distance");
}

std::vector<int> possibilities(int time)
{
    std::vector<int> result;
    for(int hold_for = 0; hold_for <= time; hold_for++)
    {
        int distance = hold_for * ( time - hold_for );
        // int release_for = time - hold_for;
        // int distance = release_for * hold_for;
        result.push_back(distance);
    }
    return result;
}

int winning_ways(int time, int distance)
{
    auto p = possibilities(time);
    return std::count_if(p.begin(), p.end(), [distance](const int d){ return d > distance;});
}

uint64_t parse_line_bignum(std::string line, std::string prefix)
{
    auto split = split_string(line, ':');
    if (split[0] != prefix) {
        return 0;
    }

    std::string nums;
    std::copy_if(split[1].begin(), split[1].end(), nums.begin(), [](char c){return c >= '0' && c <= '9';});
    return std::stoull(nums);
}

uint64_t parse_times_bignum(std::string time)
{
    return parse_line_bignum(time, "Time");
}

uint64_t parse_distances_bignum(std::string distance)
{
    return parse_line_bignum(distance, "Distance");
}

uint64_t winning_ways_quadratic(uint64_t time, uint64_t distance)
{
    // Distance = (time * hold) - (hold ^ 2)
    // Solve for quadratic: a = -1, b = time. c =-distance
    double f_time = time;
    double f_distance = distance;
    double f_det = (f_time * f_time) - (4.f * f_distance);
    double f_sol = (f_time - std::sqrt(f_det)) / 2;

    // Winners are all those between the zero-crossings
    return 1 + time - 2 * (1 + (int)f_sol );
}