#include <catch2/catch_all.hpp>
#include "day4.h"

const char* SampleInput[] = {
    "Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53",
    "Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19",
    "Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1",
    "Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83",
    "Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36",
    "Card  6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11"
};

TEST_CASE( "Day 4: Parse line 1")
{
    Card result(SampleInput[0]);
    REQUIRE(result.card == 1);
    REQUIRE(result.winners == std::vector { 41, 48, 83, 86, 17 });
    REQUIRE(result.numbers == std::vector { 83, 86, 6, 31, 17, 9, 48, 53 });
}

TEST_CASE("Day 4: scores")
{
    int expected[] = {
        8, 2, 2, 1, 0, 0
    };

    auto i = GENERATE(range(0,6));

    Card c(SampleInput[i]);
    REQUIRE(c.score() == expected[i]);
}

TEST_CASE("Day 4: Matches")
{
    int expected[] = {
        4, 2, 2, 1, 0, 0
    };
    auto i = GENERATE(range(0,6));
    Card c(SampleInput[i]);
    REQUIRE(c.matches() == expected[i]);
}

TEST_CASE("Day 4: Play")
{
    std::vector<Card> cards;
    for(auto l: SampleInput) { cards.emplace_back(l); }
    auto total = play(cards);
    REQUIRE(total == 30);
}