#include <catch2/catch_all.hpp>
#include "day3.h"

std::vector<std::string> sampleInput = {
    "467..114..",
    "...*......",
    "..35..633.",
    "......#...",
    "617*......",
    ".....+.58.",
    "..592.....",
    "......755.",
    "...$.*....",
    ".664.598.."
};

Part numbers[] = {
    Part { "467", 0, 0 },
    Part { "114", 5, 0 },
    Part { "35", 2, 2 },
    Part { "633", 6, 2 },
    Part { "617", 0, 4 },
    Part { "58", 7, 5 },
    Part { "592", 2, 6 },
    Part { "755", 6, 7 },
    Part { "664", 1, 9 },
    Part { "598", 5, 9 }
};

Symbol symbols[] = {
    Symbol { '*', 3 , 1 },
    Symbol { '#', 6, 3 },
    Symbol { '*', 3, 4 },
    Symbol { '+', 5, 5 },
    Symbol { '$', 3, 8 },
    Symbol { '*', 5, 8 }
};

TEST_CASE( "Day 3: Schematic parse: parts")
{
    Schematic s = parse_input(sampleInput);

    auto i = GENERATE(range(0, 9));
    CAPTURE(s.parts[i].number);
    CAPTURE(s.parts[i].x);
    CAPTURE(s.parts[i].y);
    REQUIRE(s.parts[i] == numbers[i]);
}

TEST_CASE( "Day 3: Schematic parse: symbols")
{
    Schematic s = parse_input(sampleInput);

    auto i = GENERATE(range(0, 5));
    CAPTURE(s.symbols[i].c);
    CAPTURE(s.symbols[i].x);
    CAPTURE(s.symbols[i].y);
    REQUIRE(s.symbols[i] == symbols[i]);
}

TEST_CASE( "Day 3: Overlaps" )
{
    Part p { "1234", 3, 7 };
    REQUIRE(p.in_expanded_bounds(0,0) == false);
    REQUIRE(p.in_expanded_bounds(3,7) == true);
    REQUIRE(p.in_expanded_bounds(2,7) == true);
    REQUIRE(p.in_expanded_bounds(2,6) == true);
    REQUIRE(p.in_expanded_bounds(6,7) == true);
    REQUIRE(p.in_expanded_bounds(7,7) == true);
    REQUIRE(p.in_expanded_bounds(7,8) == true);
    REQUIRE(p.in_expanded_bounds(8,7) == false);
}

TEST_CASE( "Day 3: Not parts")
{
    Schematic s = parse_input(sampleInput);
    auto not_parts = s.not_parts();

    REQUIRE(not_parts.size() == 2);
    REQUIRE(not_parts[0].number == "114" );
    REQUIRE(not_parts[1].number == "58" );
}

TEST_CASE( "Day 3: Parts")
{
    Schematic s = parse_input(sampleInput);
    auto not_parts = s.actual_parts();

    REQUIRE(not_parts.size() == 8);
    REQUIRE(not_parts[0].number == "467" );
    REQUIRE(not_parts[1].number == "35" );
    REQUIRE(not_parts[2].number == "633" );
    REQUIRE(not_parts[3].number == "617" );
    REQUIRE(not_parts[4].number == "592" );
    REQUIRE(not_parts[5].number == "755" );
    REQUIRE(not_parts[6].number == "664" );
    REQUIRE(not_parts[7].number == "598" );
}