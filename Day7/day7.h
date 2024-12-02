#pragma once
#include <string>
#include <map>

enum HandType {
    HighCard,
    OnePair,
    TwoPair,
    ThreeKind,
    FullHouse,
    FourKind,
    FiveKind
};

struct Hand {
    explicit Hand();
    static Hand from(std::string line);
    static Hand from_with_jokers(std::string line);
    explicit Hand(std::string cards, int bid, bool withJokers = false);

    HandType type() const;

    static bool compare(const Hand& lhs, const Hand& rhs);
    static bool compare_with_jokers(const Hand& lhs, const Hand& rhs);

    std::string hand;
    std::map<int, int> cards;
    int bid;
};

int num_from_card(char c);
char card_from_num(int i);
Hand parse_line(std::string line);