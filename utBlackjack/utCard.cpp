#include "Card.h"

#include "gtest/gtest.h"

TEST(TestCard, DefaultConstructor)
{
	Card c;

	EXPECT_TRUE(Rank::Ace == c.getRank());
	EXPECT_TRUE(Suit::Spades == c.getSuit());
	EXPECT_EQ("Ace", c.getRankString());
	EXPECT_EQ("Spades", c.getSuitString());
}

TEST(TestCard, SuitRankConstructor)
{
	Card c(Suit::Diamonds, Rank::Two);

	EXPECT_TRUE(Rank::Two == c.getRank());
	EXPECT_TRUE(Suit::Diamonds == c.getSuit());
	EXPECT_EQ("Two", c.getRankString());
	EXPECT_EQ("Diamonds", c.getSuitString());
}

TEST(TestCard, UnknownCard1)
{
	Card c(Suit::NoSuit, Rank::NoRank);

	EXPECT_TRUE(Rank::NoRank == c.getRank());
	EXPECT_TRUE(Suit::NoSuit == c.getSuit());
	EXPECT_EQ("?", c.getRankString());
	EXPECT_EQ("?", c.getSuitString());
}
