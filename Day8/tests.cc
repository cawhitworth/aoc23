#include <catch2/catch_all.hpp>
#include <vector>
#include <string>
#include "day8.h"

std::string SampleDirections = "RL";

std::vector<std::string> SampleNodes = {
    "AAA = (BBB, CCC)",
    "BBB = (DDD, EEE)",
    "CCC = (ZZZ, GGG)",
    "DDD = (DDD, DDD)",
    "EEE = (EEE, EEE)",
    "GGG = (GGG, GGG)",
    "ZZZ = (ZZZ, ZZZ)",
};

std::vector<std::string> SampleNodes2 = {
    "AAA = (BBB, BBB)",
    "BBB = (AAA, ZZZ)",
    "ZZZ = (ZZZ, ZZZ)"
};

TEST_CASE( "Day 8 Parsing", "[day8]")
{
    Map m(SampleDirections, SampleNodes);

    auto expected = std::pair<std::string, std::string> { "BBB", "CCC" };
    REQUIRE(m.node_map_["AAA"] == expected);
}

TEST_CASE( "Day 8 Solving", "[day8]")
{
    Map m(SampleDirections, SampleNodes);

    int steps = m.solve();
    REQUIRE(steps == 2);
}

TEST_CASE( "Day 8 Solving again", "[day8]")
{
    Map m("LLR", SampleNodes2);

    int steps = m.solve();
    REQUIRE(steps == 6);
}

std::vector<std::string> SampleInput3 = {
    "11A = (11B, XXX)",
    "11B = (XXX, 11Z)",
    "11Z = (11B, XXX)",
    "22A = (22B, XXX)",
    "22B = (22C, 22C)",
    "22C = (22Z, 22Z)",
    "22Z = (22B, 22B)",
    "XXX = (XXX, XXX)"
};

TEST_CASE( "Day 8 Solving part 2", "[day8]")
{
    Map m("LR", SampleInput3);

    int steps = m.solve2();
    REQUIRE(steps == 6);
}