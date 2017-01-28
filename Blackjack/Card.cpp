#include "Card.h"

using namespace std;

Card::Card() : m_suit(3), m_rank(0)
{
}

Card::Card(int suit, int rank) : m_suit(suit), m_rank(rank)
{
}

int Card::getSuit() const
{
	return m_suit;
}

int Card::getRank() const
{
	return m_rank;
}

string Card::getSuitString() const
{
	switch (m_suit)
	{
		case 0:
			return "H";
		case 1:
			return "D";
		case 2:
			return "C";
		case 3:
			return "S";
		default:
			return "?";
	}
}

string Card::getRankString() const
{
	if (m_rank > 0 && m_rank < 10)
	{
		return to_string(m_rank + 1);
	}

	switch (m_rank)
	{
		case 0:
			return "A";
		case 10:
			return "J";
		case 11:
			return "Q";
		case 12:
			return "K";
		default:
			return "?";
	}
}

ostream& operator<<(ostream& os, const Card& card)
{
	os << card.getRankString() << card.getSuitString();
	return os;
}
