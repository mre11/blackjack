#include "Deck.h"

#include <algorithm>
#include <ctime>

using namespace std;

Deck::Deck()
{
	initStandardDeck();
}

void Deck::shuffle()
{
	srand(time(0));
	random_shuffle(m_cards.begin(), m_cards.end());
}

Card Deck::deal()
{
	if (m_nextCard == m_cards.end())
		return Card();

	return *m_nextCard++;
}

void Deck::reset()
{
	initStandardDeck();
}

int Deck::count()
{
	return m_cards.end() - m_nextCard;
}

void Deck::initStandardDeck()
{
	m_cards.clear();

	for (int suit = 0; suit < 4; suit++)
	{
		for (int rank = 0; rank < 13; rank++)
		{
			m_cards.push_back(Card(suit, rank));
		}
	}

	shuffle();
	m_nextCard = m_cards.begin();
}
