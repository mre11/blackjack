#pragma once

#include "Card.h"

#include <vector>

class Deck
{
public:
	Deck();

	void shuffle();
	Card deal();
	void reset();
	int count();

private:
	void initStandardDeck();

	std::vector<Card> m_cards;
	std::vector<Card>::iterator m_nextCard;
};
