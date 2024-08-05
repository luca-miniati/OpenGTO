#include <vector>
#include <utility>
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
};

class Hand {
public:
    virtual int compare(Hand* other) = 0;
    virtual int compareHighCard(Card other) = 0;
    virtual int comparePair(Card other) = 0;
    virtual int compareTwoPair(pair<Card, Card> other) = 0;
    virtual int compareThreeOfAKind(Card other) = 0;
    virtual int compareStraight(vector<Card> other) = 0;
    virtual int compareFlush(vector<Card> other) = 0;
    virtual int compareFullHouse(pair<Card, Card> other) = 0;
    virtual int compareFourOfAKind(Card other) = 0;
    virtual int compareStraightFlush(vector<Card> other) = 0;
};

class HighCard : public Hand {
private:
    Card card;
public:
    virtual int compare(Hand* other) {
        return other->compareHighCard(this->card);
    }

    virtual int compareHighCard(Card other) {
        if (this->card.rank > other.rank) {
            return -1;
        } else if (this->card.rank < other.rank) {
            return 1;
        } else {
            return 0;
        }
    }

    virtual int comparePair(Card other) {
        return 1;
    }

    virtual int compareTwoPair(Card other) {
        return 1;
    }

    virtual int compareThreeOfAKind(Card other) {
        return 1;
    }

    virtual int compareStraight(Card other) {
        return 1;
    }

    virtual int compareFlush(Card other) {
        return 1;
    }

    virtual int compareFullHouse(Card other) {
        return 1;
    }

    virtual int compareFourOfAKind(Card other) {
        return 1;
    }

    virtual int compareStraightFlush(Card other) {
        return 1;
    }
};

class Pair : public Hand {
private:
    Card card;
public:
    virtual int compare(Hand* other) {
        return other->comparePair(this->card);
    }

    virtual int compareHighCard(Card other) {
        return -1;
    }

    virtual int comparePair(Card other) {
        if (this->card.rank > other.rank) {
            return -1;
        } else if (this->card.rank < other.rank) {
            return 1;
        } else {
            return 0;
        }
    }

    virtual int compareTwoPair(Card other) {
        return 1;
    }

    virtual int compareThreeOfAKind(Card other) {
        return 1;
    }

    virtual int compareStraight(Card other) {
        return 1;
    }

    virtual int compareFlush(Card other) {
        return 1;
    }

    virtual int compareFullHouse(Card other) {
        return 1;
    }

    virtual int compareFourOfAKind(Card other) {
        return 1;
    }

    virtual int compareStraightFlush(Card other) {
        return 1;
    }
};

class TwoPair : public Hand {
private:
    pair<Card, Card> cards;
public:
    virtual int compare(Hand* other) {
        return other->compareTwoPair(this->cards);
    }

    virtual int compareHighCard(Card other) {
        return -1;
    }

    virtual int comparePair(Card other) {
        return -1;
    }

    virtual int compareTwoPair(pair<Card, Card> other) {
        if (this->cards.first.rank > other.first.rank) {
            return -1;
        } else if (this->cards.first.rank < other.first.rank) {
            return 1;
        } else {
            if (this->cards.second.rank > other.second.rank) {
                return -1;
            } else if (this->cards.second.rank < other.second.rank) {
                return 1;
            } else {
                return 0;
            }
        }
    }

    virtual int compareThreeOfAKind(Card other) {
        return 1;
    }

    virtual int compareStraight(Card other) {
        return 1;
    }

    virtual int compareFlush(Card other) {
        return 1;
    }

    virtual int compareFullHouse(Card other) {
        return 1;
    }

    virtual int compareFourOfAKind(Card other) {
        return 1;
    }

    virtual int compareStraightFlush(Card other) {
        return 1;
    }
};

