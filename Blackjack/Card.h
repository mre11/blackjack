#pragma once

#include <iostream>
#include <string>
#include <array>

enum class Suit
{
	Hearts, Diamonds, Clubs, Spades, NoSuit
};

enum class Rank
{
	Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, NoRank
};

const std::array<Suit, 4> SUITS = { Suit::Hearts, Suit::Diamonds, Suit::Clubs, Suit::Spades };
const std::array<Rank, 13> RANKS = { Rank::Ace, Rank::Two, Rank::Three, Rank::Four, Rank::Five, Rank::Six, Rank::Seven, Rank::Eight, Rank::Nine, Rank::Ten, Rank::Jack, Rank::Queen, Rank::King };

class Card
{
public:
	Card();
	Card(Suit suit, Rank rank);

	Suit getSuit() const;
	Rank getRank() const;

	std::string getSuitString() const;
	std::string getRankString() const;

private:
	std::string suitToString(Suit suit) const;
	std::string rankToString(Rank rank) const;

	Suit m_suit;
	Rank m_rank;	
};

std::ostream& operator<<(std::ostream& os, const Card& card);
