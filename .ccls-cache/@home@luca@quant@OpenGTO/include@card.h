#ifndef CARD_H
#define CARD_H

enum Rank {
    TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};

enum Suit {
    CLUBS, DIAMONDS, HEARTS, SPADES
};

struct Card {
    Rank rank;
    Suit suit;
};

#endif
