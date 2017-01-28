#include "Card.h"

#include "gtest/gtest.h"

TEST(TestCard, DefaultConstructor)
{
	Card c;

	EXPECT_EQ(0, c.getRank());
	EXPECT_EQ(3, c.getSuit());
	EXPECT_EQ("A", c.getRankString());
	EXPECT_EQ("S", c.getSuitString());
}

TEST(TestCard, SuitRankConstructor)
{
	Card c(1, 3);

	EXPECT_EQ(3, c.getRank());
	EXPECT_EQ(1, c.getSuit());
	EXPECT_EQ("4", c.getRankString());
	EXPECT_EQ("D", c.getSuitString());
}
