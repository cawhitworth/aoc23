#include <catch2/catch_test_macros.hpp>
#include "day2.h"

const char* SampleInput[] = {
    "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green",
    "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue",
    "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red",
    "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red",
    "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"
};

TEST_CASE("Test equality - day 3")
{
    Game g1 { 1 };
    g1.draws.emplace_back(1,2,3);
    g1.draws.emplace_back(300,0,-1);

    Game g2 { 1 };
    g2.draws.emplace_back(1,2,3);
    g2.draws.emplace_back(300,0,-1);

    REQUIRE(g1 == g2);
}

TEST_CASE("Parse input line 1 - day 3")
{
    auto g = parse_line(SampleInput[0]);
    REQUIRE(g.number == 1);
}