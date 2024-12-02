#include <catch2/catch_all.hpp>
#include "day6.h"

std::vector<std::string> SampleInput = {
    "Time:      7  15   30",
    "Distance:  9  40  200"
};

TEST_CASE( "Day 6: Parse")
{
    auto t = parse_times(SampleInput[0]);
    auto d = parse_distances(SampleInput[1]);

    REQUIRE(t == decltype(t) { 7, 15, 30 });
    REQUIRE(d == decltype(d) { 9, 40, 200 });
}

TEST_CASE( "Day 6: Possibilities")
{
    auto t = parse_times(SampleInput[0]);
    auto d = parse_distances(SampleInput[1]);

    auto result = possibilities(t[0]);

    REQUIRE(result == decltype(result) { 0, 6, 10, 12, 12, 10, 6, 0 });
}

TEST_CASE( "Day 6: Winning ways")
{
    auto t = parse_times(SampleInput[0]);
    auto d = parse_distances(SampleInput[1]);

    int result = 0;
    for(int i = 0; i < t.size(); i++) {
        int r = winning_ways(t[i], d[i]);
        int rq = winning_ways_quadratic(t[i], d[i]);
        REQUIRE(r == rq);
        if (result == 0) { result = r;} else { result *= r; }
    }

    REQUIRE(result == 288);
}

TEST_CASE( "Day 6: Parse as bignum ")
{
    auto t = parse_times_bignum(SampleInput[0]);
    auto d = parse_distances_bignum(SampleInput[1]);
    REQUIRE(t == 71530ull);
    REQUIRE(d == 940200ull);
}