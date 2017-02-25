#include "Card.h"

using namespace std;

Card::Card() : m_suit(Suit::Spades), m_rank(Rank::Ace)
{
}

Card::Card(Suit suit, Rank rank) : m_suit(suit), m_rank(rank)
{
}

Suit Card::getSuit() const
{
	return m_suit;
}

Rank Card::getRank() const
{
	return m_rank;
}

string Card::getSuitString() const
{
	return suitToString(m_suit);
}

string Card::getRankString() const
{
	return rankToString(m_rank);
}

string Card::suitToString(Suit suit) const
{
	switch (suit)
	{
		case Suit::Hearts: return "Hearts";
		case Suit::Diamonds: return "Diamonds";
		case Suit::Clubs: return "Clubs";
		case Suit::Spades: return "Spades";
		default: return "?";
	}
}

string Card::rankToString(Rank rank) const
{
	switch (rank)
	{
		case Rank::Ace: return "Ace";
		case Rank::Two: return "Two";
		case Rank::Three: return "Three";
		case Rank::Four: return "Four";
		case Rank::Five: return "Five";
		case Rank::Six: return "Six";
		case Rank::Seven: return "Seven";
		case Rank::Eight: return "Eight";
		case Rank::Nine: return "Nine";
		case Rank::Ten: return "Ten";
		case Rank::Jack: return "Jack";
		case Rank::Queen: return "Queen";
		case Rank::King: return "King";
		default: return "?";
	}
}

ostream& operator<<(ostream& os, const Card& card)
{
	os << card.getRankString() << " of " << card.getSuitString();
	return os;
}
