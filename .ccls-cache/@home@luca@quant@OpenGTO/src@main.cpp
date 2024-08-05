#include <vector>
#include <utility>
#include "card.h"
using namespace std;

int compareRank(Card first, Card second) {
    if (first.rank > second.rank) {
        return 1;
    } else if (first.rank < second.rank) {
        return -1;
    } else {
        return 0;
    }
}

int compareRanks(vector<Card> first, vector<Card> second) {
    for (int i = 0; i < 5; ++i) {
        int res = compareRank(first[i], second[i]);
        if (res) {
            return res;
        }
    }
    return 0;
}

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
        return compareRank(other, this->card);
    }

    virtual int comparePair(Card other) {
        return 1;
    }

    virtual int compareTwoPair(pair<Card, Card> other) {
        return 1;
    }

    virtual int compareThreeOfAKind(Card other) {
        return 1;
    }

    virtual int compareStraight(vector<Card> other) {
        return 1;
    }

    virtual int compareFlush(vector<Card> other) {
        return 1;
    }

    virtual int compareFullHouse(pair<Card, Card> other) {
        return 1;
    }

    virtual int compareFourOfAKind(Card other) {
        return 1;
    }

    virtual int compareStraightFlush(vector<Card> other) {
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
        return compareRank(other, this->card);
    }

    virtual int compareTwoPair(pair<Card, Card> other) {
        return 1;
    }

    virtual int compareThreeOfAKind(Card other) {
        return 1;
    }

    virtual int compareStraight(vector<Card> other) {
        return 1;
    }

    virtual int compareFlush(vector<Card> other) {
        return 1;
    }

    virtual int compareFullHouse(pair<Card, Card> other) {
        return 1;
    }

    virtual int compareFourOfAKind(Card other) {
        return 1;
    }

    virtual int compareStraightFlush(vector<Card> other) {
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

    virtual int comparePair(pair<Card, Card> other) {
        return -1;
    }

    virtual int compareTwoPair(pair<Card, Card> other) {
        int res = compareRank(other.first, this->cards.first);
        if (res) {
            return res;
        } else {
            return compareRank(other.second, this->cards.second);
        }
    }

    virtual int compareThreeOfAKind(Card other) {
        return 1;
    }

    virtual int compareStraight(vector<Card> other) {
        return 1;
    }

    virtual int compareFlush(vector<Card> other) {
        return 1;
    }

    virtual int compareFullHouse(pair<Card, Card> other) {
        return 1;
    }

    virtual int compareFourOfAKind(Card other) {
        return 1;
    }

    virtual int compareStraightFlush(vector<Card> other) {
        return 1;
    }
};

class ThreeOfAKind : public Hand {
private:
    Card card;
public:
    virtual int compare(Hand* other) {
        return other->compareThreeOfAKind(this->card);
    }

    virtual int compareHighCard(Card other) {
        return -1;
    }

    virtual int comparePair(pair<Card, Card> other) {
        return -1;
    }

    virtual int compareTwoPair(pair<Card, Card> other) {
        return -1;
    }

    virtual int compareThreeOfAKind(Card other) {
        return compareRank(other, this->card);
    }

    virtual int compareStraight(vector<Card> other) {
        return 1;
    }

    virtual int compareFlush(vector<Card> other) {
        return 1;
    }

    virtual int compareFullHouse(pair<Card, Card> other) {
        return 1;
    }

    virtual int compareFourOfAKind(Card other) {
        return 1;
    }

    virtual int compareStraightFlush(vector<Card> other) {
        return 1;
    }
};

class Straight : public Hand {
private:
    vector<Card> cards;
public:
    virtual int compare(Hand* other) {
        return other->compareStraight(this->cards);
    }

    virtual int compareHighCard(Card other) {
        return -1;
    }

    virtual int comparePair(pair<Card, Card> other) {
        return -1;
    }

    virtual int compareTwoPair(pair<Card, Card> other) {
        return -1;
    }

    virtual int compareThreeOfAKind(Card other) {
        return -1;
    }

    virtual int compareStraight(vector<Card> other) {
        return compareRanks(other, this->cards);
    }

    virtual int compareFlush(vector<Card> other) {
        return 1;
    }

    virtual int compareFullHouse(pair<Card, Card> other) {
        return 1;
    }

    virtual int compareFourOfAKind(Card other) {
        return 1;
    }

    virtual int compareStraightFlush(vector<Card> other) {
        return 1;
    }
};

class Flush : public Hand {
private:
    vector<Card> cards;
public:
    virtual int compare(Hand* other) {
        return other->compareFlush(this->cards);
    }

    virtual int compareHighCard(Card other) {
        return -1;
    }

    virtual int comparePair(pair<Card, Card> other) {
        return -1;
    }

    virtual int compareTwoPair(pair<Card, Card> other) {
        return -1;
    }

    virtual int compareThreeOfAKind(Card other) {
        return -1;
    }

    virtual int compareStraight(vector<Card> other) {
        return -1;
    }

    virtual int compareFlush(vector<Card> other) {
        return compareRanks(other, this->cards);
    }

    virtual int compareFullHouse(pair<Card, Card> other) {
        return 1;
    }

    virtual int compareFourOfAKind(Card other) {
        return 1;
    }

    virtual int compareStraightFlush(vector<Card> other) {
        return 1;
    }
};

class FullHouse : public Hand {
private:
    pair<Card, Card> cards;
public:
    virtual int compare(Hand* other) {
        return other->compareFullHouse(this->cards);
    }

    virtual int compareHighCard(Card other) {
        return -1;
    }

    virtual int comparePair(pair<Card, Card> other) {
        return -1;
    }

    virtual int compareTwoPair(pair<Card, Card> other) {
        return -1;
    }

    virtual int compareThreeOfAKind(Card other) {
        return -1;
    }

    virtual int compareStraight(vector<Card> other) {
        return -1;
    }

    virtual int compareFlush(vector<Card> other) {
        return -1;
    }

    virtual int compareFullHouse(pair<Card, Card> other) {
        int res = compareRank(other.first, this->cards.first);
        if (res) {
            return res;
        } else {
            return compareRank(other.second, this->cards.second);
        }
    }

    virtual int compareFourOfAKind(Card other) {
        return 1;
    }

    virtual int compareStraightFlush(vector<Card> other) {
        return 1;
    }
};

class FourOfAKind : public Hand {
private:
    Card card;
public:
    virtual int compare(Hand* other) {
        return other->compareFourOfAKind(this->card);
    }

    virtual int compareHighCard(Card other) {
        return -1;
    }

    virtual int comparePair(pair<Card, Card> other) {
        return -1;
    }

    virtual int compareTwoPair(pair<Card, Card> other) {
        return -1;
    }

    virtual int compareThreeOfAKind(Card other) {
        return -1;
    }

    virtual int compareStraight(vector<Card> other) {
        return -1;
    }

    virtual int compareFlush(vector<Card> other) {
        return -1;
    }

    virtual int compareFullHouse(pair<Card, Card> other) {
        return -1;
    }

    virtual int compareFourOfAKind(Card other) {
        return compareRank(other, this->card);
    }

    virtual int compareStraightFlush(vector<Card> other) {
        return 1;
    }
};


class StraightFlush : public Hand {
private:
    vector<Card> cards;
public:
    virtual int compare(Hand* other) {
        return other->compareStraightFlush(this->cards);
    }

    virtual int compareHighCard(Card other) {
        return -1;
    }

    virtual int comparePair(pair<Card, Card> other) {
        return -1;
    }

    virtual int compareTwoPair(pair<Card, Card> other) {
        return -1;
    }

    virtual int compareThreeOfAKind(Card other) {
        return -1;
    }

    virtual int compareStraight(vector<Card> other) {
        return -1;
    }

    virtual int compareFlush(vector<Card> other) {
        return -1;
    }

    virtual int compareFullHouse(pair<Card, Card> other) {
        return -1;
    }

    virtual int compareFourOfAKind(Card other) {
        return -1;
    }

    virtual int compareStraightFlush(vector<Card> other) {
        return compareRanks(other, this->cards);
    }
};

int main() {

}
