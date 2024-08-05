#include <gtest/gtest.h>
#include "card.h"

TEST(HandTest, BasicHands) {
    Card aceOfSpades("As");
    Card kingOfDiamonds("Kd");

    HighCard aceHigh(aceOfSpades);
    HighCard kingHigh(kingOfDiamonds);

    EXPECT_EQ(aceHigh.compare(kingHigh), 1);
    EXPECT_EQ(kingHigh.compare(aceHigh), -1);
}
