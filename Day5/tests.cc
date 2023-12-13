#include <catch2/catch_all.hpp>
#include "day5.h"

std::vector<std::string> SampleInput = {
    "seeds: 79 14 55 13",
    "",
    "seed-to-soil map:",
    "50 98 2",
    "52 50 48",
    "",
    "soil-to-fertilizer map:",
    "0 15 37",
    "37 52 2",
    "39 0 15",
    "",
    "fertilizer-to-water map:",
    "49 53 8",
    "0 11 42",
    "42 0 7",
    "57 7 4",
    "",
    "water-to-light map:",
    "88 18 7",
    "18 25 70",
    "",
    "light-to-temperature map:",
    "45 77 23",
    "81 45 19",
    "68 64 13",
    "",
    "temperature-to-humidity map:",
    "0 69 1",
    "1 0 69",
    "",
    "humidity-to-location map:",
    "60 56 37",
    "56 93 4",
};

TEST_CASE( "Day 5: parse input")
{
    Almanac a(SampleInput);
    REQUIRE(a.seeds == decltype(a.seeds) { 79, 14, 55, 13 });
    REQUIRE(a.maps[0].from == "seed");
    REQUIRE(a.maps[0].to == "soil");
    REQUIRE(a.maps[0].ranges[0] == Range(50, 98, 2) );
}

TEST_CASE ( "Day 5: Seed-to-soil")
{
    Almanac a(SampleInput);

    REQUIRE(a.maps[0].map(79) == 81);
    REQUIRE(a.maps[0].map(14) == 14);
    REQUIRE(a.maps[0].map(55) == 57);
    REQUIRE(a.maps[0].map(13) == 13);
    REQUIRE(a.maps[0].map(99) == 51);
}

TEST_CASE("Day 5: Map through")
{
    Almanac a(SampleInput);
    REQUIRE(a.map_through(79) == 82);
    REQUIRE(a.map_through(14) == 43);
    REQUIRE(a.map_through(55) == 86);
    REQUIRE(a.map_through(13) == 35);
}