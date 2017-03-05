#include "Player.h"

using namespace std;

Player::Player() : m_handScore(0), m_chips (50)
{
}

int Player::getScore() const
{
	return m_handScore;
}

void Player::setScore(int score)
{
	m_handScore = score;
}

void Player::bet(int amount)
{
	if (amount > m_chips)
		return;

	m_currentBet = amount;
	m_chips -= amount;
}

int Player::getCurrentBet() const
{
	return m_currentBet;
}

void Player::dealCard(Card& card)
{
	m_hand.push_back(card);
}

const vector<Card>& Player::getHand() const
{
	return m_hand;
}

void Player::resetHand()
{
	m_currentBet = 0;
	m_handScore = 0;
	m_hand.clear();
}

void Player::pay(unsigned int amount)
{
	m_chips += amount;
}
