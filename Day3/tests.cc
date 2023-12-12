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
    Part { 467, 0, 0 },
    Part { 114, 5, 0 },
    Part { 35, 2, 2 },
    Part { 633, 6, 2 },
    Part { 617, 0, 4 },
    Part { 58, 7, 5 },
    Part { 592, 2, 6 },
    Part { 755, 6, 7 },
    Part { 664, 1, 9 },
    Part { 598, 5, 9 }
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