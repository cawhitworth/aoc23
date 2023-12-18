#include <catch2/catch_all.hpp>
#include "day7.h"

const std::string SampleInput[] = {
    "32T3K 765",
    "T55J5 684",
    "KK677 28",
    "KTJJT 220",
    "QQQJA 483"
};

TEST_CASE( "Day 7: Convert to and from" )
{
    std::string input = "23456789TJQKA";

    for(auto s : input) {
        REQUIRE(card_from_num(num_from_card(s)) == s);
    }

    input = "01BCDEFGHILMNOPRSUVWXYZ";
    for(auto s : input) {
        REQUIRE(num_from_card(s) == -1);
    }
}

TEST_CASE("Day 7: Hands")
{
    auto g = GENERATE(table<std::string, HandType> ({
         { "AAAAA", FiveKind },
         { "KK9KK", FourKind },
         { "32323", FullHouse },
         { "TTT45", ThreeKind },
         { "45456", TwoPair },
         { "898KQ", OnePair },
         { "7294J", HighCard}
    }));
    
    auto hand = std::get<0>(g);
    auto type = std::get<1>(g);

    CAPTURE(hand);
    Hand h(hand, 0);
    REQUIRE(h.type() == type);
}