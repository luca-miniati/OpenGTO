#include <vector>
#include <utility>
#include "card.h"
using namespace std;

int compareRank(const Card& first, const Card& second) {
    if (first.rank > second.rank) {
        return 1;
    } else if (first.rank < second.rank) {
        return -1;
    } else {
        return 0;
    }
}

int compareRanks(const vector<Card>& first, const vector<Card>& second) {
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
    virtual int compare(const Hand& other) const = 0;
    virtual int compareHighCard(const Card& other) const = 0;
    virtual int comparePair(const Card& other) const = 0;
    virtual int compareTwoPair(const pair<Card, Card>& other) const = 0;
    virtual int compareThreeOfAKind(const Card& other) const = 0;
    virtual int compareStraight(const vector<Card>& other) const = 0;
    virtual int compareFlush(const vector<Card>& other) const = 0;
    virtual int compareFullHouse(const pair<Card, Card>& other) const = 0;
    virtual int compareFourOfAKind(const Card& other) const = 0;
    virtual int compareStraightFlush(const vector<Card>& other) const = 0;
};

class HighCard : public Hand {
private:
    Card card;
public:
    HighCard(const Card& card) : card(card) {}

    virtual int compare(const Hand& other) const override {
        return other.compareHighCard(this->card);
    }

    virtual int compareHighCard(const Card& other) const override {
        return compareRank(other, this->card);
    }

    virtual int comparePair(const Card& other) const override {
        return 1;
    }

    virtual int compareTwoPair(const pair<Card, Card>& other) const override {
        return 1;
    }

    virtual int compareThreeOfAKind(const Card& other) const override {
        return 1;
    }

    virtual int compareStraight(const vector<Card>& other) const override {
        return 1;
    }

    virtual int compareFlush(const vector<Card>& other) const override {
        return 1;
    }

    virtual int compareFullHouse(const pair<Card, Card>& other) const override {
        return 1;
    }

    virtual int compareFourOfAKind(const Card& other) const override {
        return 1;
    }

    virtual int compareStraightFlush(const vector<Card>& other) const override {
        return 1;
    }
};

class Pair : public Hand {
private:
    Card card;
public:
    Pair(const Card& card) : card(card) {}

    virtual int compare(const Hand& other) const override {
        return other.comparePair(this->card);
    }

    virtual int compareHighCard(const Card& other) const override {
        return -1;
    }

    virtual int comparePair(const Card& other) const override {
        return compareRank(other, this->card);
    }

    virtual int compareTwoPair(const pair<Card, Card>& other) const override {
        return 1;
    }

    virtual int compareThreeOfAKind(const Card& other) const override {
        return 1;
    }

    virtual int compareStraight(const vector<Card>& other) const override {
        return 1;
    }

    virtual int compareFlush(const vector<Card>& other) const override {
        return 1;
    }

    virtual int compareFullHouse(const pair<Card, Card>& other) const override {
        return 1;
    }

    virtual int compareFourOfAKind(const Card& other) const override {
        return 1;
    }

    virtual int compareStraightFlush(const vector<Card>& other) const override {
        return 1;
    }
};

class TwoPair : public Hand {
private:
    pair<Card, Card> cards;
public:
    TwoPair(const pair<Card, Card>& cards) : cards(cards) {}

    virtual int compare(const Hand& other) const override {
        return other.compareTwoPair(this->cards);
    }

    virtual int compareHighCard(const Card& other) const override {
        return -1;
    }

    virtual int comparePair(const Card& other) const override {
        return -1;
    }

    virtual int compareTwoPair(const pair<Card, Card>& other) const override {
        int res = compareRank(other.first, this->cards.first);
        if (res) {
            return res;
        } else {
            return compareRank(other.second, this->cards.second);
        }
    }

    virtual int compareThreeOfAKind(const Card& other) const override {
        return 1;
    }

    virtual int compareStraight(const vector<Card>& other) const override {
        return 1;
    }

    virtual int compareFlush(const vector<Card>& other) const override {
        return 1;
    }

    virtual int compareFullHouse(const pair<Card, Card>& other) const override {
        return 1;
    }

    virtual int compareFourOfAKind(const Card& other) const override {
        return 1;
    }

    virtual int compareStraightFlush(const vector<Card>& other) const override {
        return 1;
    }
};

class ThreeOfAKind : public Hand {
private:
    Card card;
public:
    ThreeOfAKind(const Card& card) : card(card) {}

    virtual int compare(const Hand& other) const override {
        return other.compareThreeOfAKind(this->card);
    }

    virtual int compareHighCard(const Card& other) const override {
        return -1;
    }

    virtual int comparePair(const Card& other) const override {
        return -1;
    }

    virtual int compareTwoPair(const pair<Card, Card>& other) const override {
        return -1;
    }

    virtual int compareThreeOfAKind(const Card& other) const override {
        return compareRank(other, this->card);
    }

    virtual int compareStraight(const vector<Card>& other) const override {
        return 1;
    }

    virtual int compareFlush(const vector<Card>& other) const override {
        return 1;
    }

    virtual int compareFullHouse(const pair<Card, Card>& other) const override {
        return 1;
    }

    virtual int compareFourOfAKind(const Card& other) const override {
        return 1;
    }

    virtual int compareStraightFlush(const vector<Card>& other) const override {
        return 1;
    }
};

class Straight : public Hand {
private:
    vector<Card> cards;
public:
    Straight(const vector<Card>& cards) : cards(cards) {}

    virtual int compare(const Hand& other) const override {
        return other.compareStraight(this->cards);
    }

    virtual int compareHighCard(const Card& other) const override {
        return -1;
    }

    virtual int comparePair(const Card& other) const override {
        return -1;
    }

    virtual int compareTwoPair(const pair<Card, Card>& other) const override {
        return -1;
    }

    virtual int compareThreeOfAKind(const Card& other) const override {
        return -1;
    }

    virtual int compareStraight(const vector<Card>& other) const override {
        return compareRanks(other, this->cards);
    }

    virtual int compareFlush(const vector<Card>& other) const override {
        return 1;
    }

    virtual int compareFullHouse(const pair<Card, Card>& other) const override {
        return 1;
    }

    virtual int compareFourOfAKind(const Card& other) const override {
        return 1;
    }

    virtual int compareStraightFlush(const vector<Card>& other) const override {
        return 1;
    }
};

class Flush : public Hand {
private:
    vector<Card> cards;
public:
    Flush(const vector<Card>& cards) : cards(cards) {}

    virtual int compare(const Hand& other) const override {
        return other.compareFlush(this->cards);
    }

    virtual int compareHighCard(const Card& other) const override {
        return -1;
    }

    virtual int comparePair(const Card& other) const override {
        return -1;
    }

    virtual int compareTwoPair(const pair<Card, Card>& other) const override {
        return -1;
    }

    virtual int compareThreeOfAKind(const Card& other) const override {
        return -1;
    }

    virtual int compareStraight(const vector<Card>& other) const override {
        return -1;
    }

    virtual int compareFlush(const vector<Card>& other) const override {
        return compareRanks(other, this->cards);
    }

    virtual int compareFullHouse(const pair<Card, Card>& other) const override {
        return 1;
    }

    virtual int compareFourOfAKind(const Card& other) const override {
        return 1;
    }

    virtual int compareStraightFlush(const vector<Card>& other) const override {
        return 1;
    }
};

class FullHouse : public Hand {
private:
    pair<Card, Card> cards;
public:
    FullHouse(const pair<Card, Card>& cards) : cards(cards) {}

    virtual int compare(const Hand& other) const override {
        return other.compareFullHouse(this->cards);
    }

    virtual int compareHighCard(const Card& other) const override {
        return -1;
    }

    virtual int comparePair(const Card& other) const override {
        return -1;
    }

    virtual int compareTwoPair(const pair<Card, Card>& other) const override {
        return -1;
    }

    virtual int compareThreeOfAKind(const Card& other) const override {
        return -1;
    }

    virtual int compareStraight(const vector<Card>& other) const override {
        return -1;
    }

    virtual int compareFlush(const vector<Card>& other) const override {
        return -1;
    }

    virtual int compareFullHouse(const pair<Card, Card>& other) const override {
        int res = compareRank(other.first, this->cards.first);
        if (res) {
            return res;
        } else {
            return compareRank(other.second, this->cards.second);
        }
    }

    virtual int compareFourOfAKind(const Card& other) const override {
        return 1;
    }

    virtual int compareStraightFlush(const vector<Card>& other) const override {
        return 1;
    }
};

class FourOfAKind : public Hand {
private:
    Card card;
public:
    FourOfAKind(const Card& card) : card(card) {}

    virtual int compare(const Hand& other) const override {
        return other.compareFourOfAKind(this->card);
    }

    virtual int compareHighCard(const Card& other) const override {
        return -1;
    }

    virtual int comparePair(const Card& other) const override {
        return -1;
    }

    virtual int compareTwoPair(const pair<Card, Card>& other) const override {
        return -1;
    }

    virtual int compareThreeOfAKind(const Card& other) const override {
        return -1;
    }

    virtual int compareStraight(const vector<Card>& other) const override {
        return -1;
    }

    virtual int compareFlush(const vector<Card>& other) const override {
        return -1;
    }

    virtual int compareFullHouse(const pair<Card, Card>& other) const override {
        return -1;
    }

    virtual int compareFourOfAKind(const Card& other) const override {
        return compareRank(other, this->card);
    }

    virtual int compareStraightFlush(const vector<Card>& other) const override {
        return 1;
    }
};


class StraightFlush : public Hand {
private:
    vector<Card> cards;
public:
    StraightFlush(const vector<Card>& cards) : cards(cards) {}

    virtual int compare(const Hand& other) const override {
        return other.compareStraightFlush(this->cards);
    }

    virtual int compareHighCard(const Card& other) const override {
        return -1;
    }

    virtual int comparePair(const Card& other) const override {
        return -1;
    }

    virtual int compareTwoPair(const pair<Card, Card>& other) const override {
        return -1;
    }

    virtual int compareThreeOfAKind(const Card& other) const override {
        return -1;
    }

    virtual int compareStraight(const vector<Card>& other) const override {
        return -1;
    }

    virtual int compareFlush(const vector<Card>& other) const override {
        return -1;
    }

    virtual int compareFullHouse(const pair<Card, Card>& other) const override {
        return -1;
    }

    virtual int compareFourOfAKind(const Card& other) const override {
        return -1;
    }

    virtual int compareStraightFlush(const vector<Card>& other) const override {
        return compareRanks(other, this->cards);
    }
};

int main() {

}
