#include <string>
#include <map>

#include "day7.h"
#include "utils.h"

int num_from_card(char c)
{
    if (c >= '2' && c <= '9') {
        return c - '0';
    }
    switch (c) {
        case 'T': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        case 'A': return 14;
        default: return -1;
    }

    return -1;
}

char card_from_num(int i)
{
    static std::string cards = "0123456789TJQKA";

    if (i <0 || i >= cards.length()) {
        return '\0';
    }

    return cards[i];
}

Hand Hand::from(std::string line)
{
    auto split = split_string(line, ' ');
    auto hand = split[0];
    auto bid = split[1];
    return Hand(hand, std::stoi(bid));
}

Hand::Hand(std::string hand, int bid)
{
    std::vector<int> cardScores;
    cardScores.resize(hand.length());
    std::transform(hand.begin(), hand.end(), cardScores.begin(), [](char c) { return num_from_card(c); });
    for(int i = 0; i < 13; i++) { cards[i] = 0; }

    for (auto c : cardScores) {
        cards[c] += 1;
    }

    this->hand = hand;
    this->bid = bid;
}

HandType Hand::type()
{
    bool three = false;;
    int twos = 0;
    for(auto c: cards) {
        if (c.second == 5) {
            return FiveKind;
        }
        if (c.second == 4) {
            return FourKind;
        }
        if (c.second == 3) {
            three = true;
        }
        if (c.second == 2) {
            twos ++;
        }
    }
    if (three) {
        if (twos != 0) {
            return FullHouse;
        }
        return ThreeKind;
    }
    if (twos == 2) {
        return TwoPair;
    }
    if (twos == 1) {
        return OnePair;
    }
    return HighCard;
}