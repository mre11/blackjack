#include "Deck.h"

#include <algorithm>
#include <ctime>
#include <assert.h>

using namespace std;

Deck::Deck()
{
	initStandardDeck();
}

void Deck::shuffle()
{
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(m_cards.begin(), m_cards.end());
}

Card Deck::deal()
{
	assert(m_nextCard != m_cards.end());
	return *(m_nextCard++);
}

void Deck::reset()
{
	initStandardDeck();
}

int Deck::count()
{
	return static_cast<int>(m_cards.end() - m_nextCard);
}

void Deck::initStandardDeck()
{
	m_cards.clear();

	for (auto suit : SUITS)
	{
		for (auto rank : RANKS)
		{
			m_cards.push_back(Card(suit, rank));
		}
	}

	shuffle();
	m_nextCard = m_cards.begin();
}
