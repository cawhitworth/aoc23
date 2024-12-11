#include <catch2/catch_all.hpp>
#include "day7.h"

const std::vector<std::string> SampleInput = {
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

TEST_CASE("Day 7: Comparisons - everything beats hand 1")
{
    std::vector<Hand> h;
    h.resize(5);
    std::transform(SampleInput.begin(), SampleInput.end(), h.begin(), Hand::from);

    auto i = GENERATE(range(1,5));
    REQUIRE( Hand::compare(h[0], h[i]) == true );
}

TEST_CASE("Day 7: Comparisons - hand 5 beats everything")
{
    std::vector<Hand> h;
    h.resize(5);
    std::transform(SampleInput.begin(), SampleInput.end(), h.begin(), Hand::from);

    auto i = GENERATE(range(0,4));
    CAPTURE(h[i].hand);
    REQUIRE( Hand::compare(h[i], h[4]) == true );
}

TEST_CASE("Day 7: Comparisons - other checks")
{
    std::vector<Hand> h;
    h.resize(5);
    std::transform(SampleInput.begin(), SampleInput.end(), h.begin(), Hand::from);

    REQUIRE(Hand::compare(h[3], h[2]) == true);

    REQUIRE(Hand::compare(h[1], h[1]) == false);
}

TEST_CASE("Day 7: Comparisons - ordering")
{
    std::vector<Hand> h;
    h.resize(5);
    std::transform(SampleInput.begin(), SampleInput.end(), h.begin(), Hand::from);

    std::sort(h.begin(), h.end(), Hand::compare);

    REQUIRE(h[0].hand == "32T3K");
    REQUIRE(h[1].hand == "KTJJT");
    REQUIRE(h[2].hand == "KK677");
    REQUIRE(h[3].hand == "T55J5");
    REQUIRE(h[4].hand == "QQQJA");
}

TEST_CASE("Day 7: Winnings")
{
    std::vector<Hand> h;
    h.resize(5);
    std::transform(SampleInput.begin(), SampleInput.end(), h.begin(), Hand::from);

    std::sort(h.begin(), h.end(), Hand::compare);

    int rank = 1;
    int score = 0;
    for(auto hand: h)
    {
        score += hand.bid * rank;
        rank ++;
    }

    REQUIRE(score == 6440);
}

TEST_CASE("Day 7: Comparisons - ordering with jokers (part 2)")
{
    std::vector<Hand> h;
    h.resize(5);
    std::transform(SampleInput.begin(), SampleInput.end(), h.begin(), Hand::from_with_jokers);

    REQUIRE(h[0].type() == OnePair);
    REQUIRE(h[1].type() == FourKind);
    REQUIRE(h[2].type() == TwoPair);
    REQUIRE(h[3].type() == FourKind);
    REQUIRE(h[4].type() == FourKind);

    for(int i =0; i < 5; i++) {
        if (i == 3) continue;
        CAPTURE(i);
        REQUIRE(Hand::compare_with_jokers(h[i], h[3]) == true);
    }

    std::sort(h.begin(), h.end(), Hand::compare_with_jokers);

    REQUIRE(h[0].hand == "32T3K");
    REQUIRE(h[1].hand == "KK677");
    REQUIRE(h[2].hand == "T55J5");
    REQUIRE(h[3].hand == "QQQJA");
    REQUIRE(h[4].hand == "KTJJT");
    
        int rank = 1;
    int score = 0;
    for(auto hand: h)
    {
        score += hand.bid * rank;
        rank ++;
    }

    REQUIRE(score == 5905);
}

TEST_CASE("Day 7: Comparisons - breaking ties with jokers (part 2)")
{
    auto hand1 = Hand::from_with_jokers("JKKK2 1");
    auto hand2 = Hand::from_with_jokers("QQQQ2 1");
    auto hand3 = Hand::from_with_jokers("KJJQJ 1");

    REQUIRE(hand1.type() == FourKind);
    REQUIRE(hand2.type() == FourKind);
    REQUIRE(hand3.type() == FourKind);

    REQUIRE(Hand::compare_with_jokers(hand1, hand2));
    REQUIRE(Hand::compare_with_jokers(hand1, hand3));
    REQUIRE(Hand::compare_with_jokers(hand2, hand3));
}

TEST_CASE("Day 7: Comparisons - hand types with jokers (part 2)")
{
    auto hand1 = Hand::from_with_jokers("KKQQQ 1");
    auto hand2 = Hand::from_with_jokers("JJKQA 1");
    auto hand3 = Hand::from_with_jokers("JKQA9 1");
    auto hand4 = Hand::from_with_jokers("JJJQA 1");
    auto hand5 = Hand::from_with_jokers("JJJJA 1");
    auto hand6 = Hand::from_with_jokers("JQQAA 1");

    REQUIRE(hand1.type() == FullHouse);
    REQUIRE(hand2.type() == ThreeKind);
    REQUIRE(hand3.type() == OnePair);
    REQUIRE(hand4.type() == FourKind);
    REQUIRE(hand5.type() == FiveKind);
    REQUIRE(hand6.type() == FullHouse);
}