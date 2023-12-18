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
    static Hand from(std::string line);
    Hand(std::string cards, int bid);

    HandType type();

    std::string hand;
    std::map<int, int> cards;
    int bid;
};

int num_from_card(char c);
char card_from_num(int i);
Hand parse_line(std::string line);