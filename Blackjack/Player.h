#pragma once

#include "Card.h"

#include <vector>
#include <memory>

class Player
{
public:
	Player();

	int getScore() const;
	void setScore(int score);

	void bet(int amount);
	int getCurrentBet() const;
	void dealCard(Card& card);
	const std::vector<Card>& getHand() const;
	void resetHand();
	void pay(unsigned int amount);

private:
	std::vector<Card> m_hand;
	int m_handScore;
	int m_chips;
	int m_currentBet;
};
