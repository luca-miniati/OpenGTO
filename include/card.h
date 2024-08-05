#ifndef CARD_H
#define CARD_H

#include <stdexcept>
#include <string>
using namespace std;

enum Rank {
    TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};

enum Suit {
    CLUBS, DIAMONDS, HEARTS, SPADES
};

struct Card {
    Rank rank;
    Suit suit;

    Card(Rank r, Suit s) : rank(r), suit(s) {}
    Card(string s) {
        switch (s[0]) {
            case '2': rank = TWO; break;
            case '3': rank = THREE; break;
            case '4': rank = FOUR; break;
            case '5': rank = FIVE; break;
            case '6': rank = SIX; break;
            case '7': rank = SEVEN; break;
            case '8': rank = EIGHT; break;
            case '9': rank = NINE; break;
            case 'T': rank = TEN; break;
            case 'J': rank = JACK; break;
            case 'Q': rank = QUEEN; break;
            case 'K': rank = KING; break;
            case 'A': rank = ACE; break;
            default: throw invalid_argument("Invalid rank character: " + s[0]);
        }

        switch (s[1]) {
            case 'C': suit = CLUBS; break;
            case 'D': suit = DIAMONDS; break;
            case 'H': suit = HEARTS; break;
            case 'S': suit = SPADES; break;
            default: throw invalid_argument("Invalid suit character: " + s[1]);
        }
    }
};

#endif
