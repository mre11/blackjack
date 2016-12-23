#pragma once

#include <vector>
#include <memory>

#include "Card.h"

class Player
{
public:
	Player();

	void dealCard(Card card);
	const std::vector<Card>& getHand() const;
	void resetHand();

private:
	std::vector<Card> m_hand;
	//int money;
};

