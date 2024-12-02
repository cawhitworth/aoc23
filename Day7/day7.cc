#include <string>
#include <map>
#include <iostream>

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

Hand Hand::from_with_jokers(std::string line)
{
    auto split = split_string(line, ' ');
    auto hand = split[0];
    auto bid = split[1];
    return Hand(hand, std::stoi(bid), true);
}

Hand::Hand()
{
    this->hand = "INVLD";
    this->bid = 0;
}

Hand::Hand(std::string hand, int bid, bool withJokers)
{
    std::vector<int> cardScores;
    cardScores.resize(hand.length());
    std::transform(hand.begin(), hand.end(), cardScores.begin(), num_from_card);
    for(int i = 0; i < 13; i++) { cards[i] = 0; }

    for (auto c : cardScores) {
        cards[c] += 1;
    }

    if (withJokers) {
        int joker = num_from_card('J');
        int jokerScore = cards[joker];
        for(int i=0; i < this->cards.size(); i ++) {
            if (i == joker) continue;
            if (cards[i] != 0) cards[i] += jokerScore;
        }
    }
    
    this->hand = hand;
    this->bid = bid;
}

HandType Hand::type() const
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

bool Hand::compare(const Hand& lhs, const Hand& rhs)
{
    auto lhsType = lhs.type();
    auto rhsType = rhs.type();

    if (lhsType < rhsType) {
        return true;
    }

    if (lhsType > rhsType) {
        return false;
    }

    if (lhsType == rhsType) {
        for(int i = 0; i < lhs.hand.length(); i++) {
            if (num_from_card(lhs.hand[i]) < num_from_card(rhs.hand[i]))
            {
                return true;
            }
            if (num_from_card(lhs.hand[i]) > num_from_card(rhs.hand[i]))
            {
                return false;
            }
        }
    }

    return false;
}

bool Hand::compare_with_jokers(const Hand& lhs, const Hand& rhs)
{
    auto lhsType = lhs.type();
    auto rhsType = rhs.type();

    if (lhsType < rhsType) {
        return true;
    }

    if (lhsType > rhsType) {
        return false;
    }

    int joker = num_from_card('J');
    if (lhsType == rhsType) {
        for(int i = 0; i < lhs.hand.length(); i++) {
            int lhsNum = num_from_card(lhs.hand[i]);
            if (lhsNum ==joker) lhsNum = 1;

            int rhsNum = num_from_card(rhs.hand[i]);
            if (rhsNum ==joker) rhsNum = 1;

            if (lhsNum < rhsNum)
            {
                return true;
            }
            if (lhsNum > rhsNum)
            {
                return false;
            }
        }
    }

    return false;
}